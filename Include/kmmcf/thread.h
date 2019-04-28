/* kmmcf KaMe MCU Common Framework
 * 
 * MIT License
 * 
 * Copyright (c) 2019 KaMeTang <KaMeTang@umkmtw.org>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef KMMCF_THREAD_H
#define KMMCF_THREAD_H

#include "countdown.h"
#include "event.h"
#include "list.h"
#include "logger.h"

namespace kmmcf
{
    // prototype

    class Thread_t;

    namespace Thread
    {
        ///
        /// hidden
        ///
        namespace _
        {
            extern List::List_t<Thread_t> thread_list;
            extern Thread_t*              thread_cur;
        }    // namespace _

        ///
        /// Thread status
        ///
        enum STATUS
        {
            ///
            /// Thread stopped
            ///
            /// not in list
            ///
            STOPPED,

            ///
            /// Thread wait for time or event
            ///
            /// in list
            ///
            WAIT,

            ///
            /// Thread still running
            ///
            /// in list
            ///
            RUN,
        };

        enum WAKEUP
        {
            ///
            /// RUN->RUN
            ///
            NORMAL,

            ///
            /// WAIT->RUN when event trig
            ///
            WAIT,

            ///
            /// WAIT->RUN when time done or timeout
            ///
            TIMEOUT,
        };
    }    // namespace Thread


    class Thread_t : public List::Node_t<Thread_t>
    {
        private:
        ///
        /// name of thread
        ///
        const char* name;
        ///
        /// Thread handler
        ///
        void (*handler)(void);
        ///
        /// thread status
        ///
        Event_t status;
        ///
        /// Thread wakeup reason
        ///
        Event_t wakeup;
        ///
        /// timeout countdown
        ///
        Cd_t timeout;
        ///
        /// timeout ticks
        ///
        uint32_t ticks;
        ///
        /// wait event
        ///
        Event_t* event;
        ///
        /// mask for wait event
        ///
        uint32_t event_mask;
        ///
        /// logger
        ///
        Logger::Logger_t log;
        ///
        /// resume address
        ///
        /// in switch, will be line
        ///
        uint32_t addr;

        public:
        ///
        /// constructor
        /// @param handler handler default NULL
        ///
        Thread_t(const char* name, void (*handler)(void) = NULL);

        ///
        /// Set handler for thread
        /// @param handler thread handler
        ///
        void SetHandler(void (*handler)(void));

        ///
        /// Start thread
        ///
        void Start(void);

        ///
        /// Stop thread
        ///
        void Stop(void);

        ///
        /// Execute current thread
        ///
        void __Execute(void);

        ///
        /// wait for event
        /// @param event event
        /// @param mask mask to check event
        /// @param timeout timeout
        ///
        void __Wait(Event_t* event, uint32_t mask, uint32_t timeout);

        ///
        /// wait for timeout
        /// @param timeout
        ///
        void __Wait(uint32_t timeout)
        {
            this->__Wait(NULL, 0, timeout);
        }

        ///
        /// config for wait thread join
        /// @param thread thread object
        /// @param timeout timeout ticks
        ///
        void __Wait(Thread_t& thread, uint32_t timeout)
        {
            this->__Wait(&thread.status, (1 << Thread::STATUS::STOPPED), timeout);
        }

        ///
        /// get addr for handler
        /// @return addr
        ///
        uint32_t __GetAddr(void)
        {
            return this->addr;
        }

        ///
        /// end thread for handler
        ///
        void __End(void)
        {
            this->status.Set(Thread::STATUS::STOPPED);
        }

        ///
        /// config for yield
        /// @param line line number as addr
        ///
        void __Yield(uint32_t line)
        {
            this->addr = line;
        }

        ///
        /// is thread wakeup by timeout?
        /// @return [true] timeout
        /// @return [false] not timeout
        ///
        bool __IsTimeout(void)
        {
            return this->wakeup.IsSet(Thread::WAKEUP::TIMEOUT);
        }
    };

}    // namespace kmmcf

// :::'###::::'########::'####::::::::::'##::::'##::::'###::::'##::: ##:'########::'##:::::::'########:'########::
// ::'## ##::: ##.... ##:. ##::::::::::: ##:::: ##:::'## ##::: ###:: ##: ##.... ##: ##::::::: ##.....:: ##.... ##:
// :'##:. ##:: ##:::: ##:: ##::::::::::: ##:::: ##::'##:. ##:: ####: ##: ##:::: ##: ##::::::: ##::::::: ##:::: ##:
// '##:::. ##: ########::: ##::'#######: #########:'##:::. ##: ## ## ##: ##:::: ##: ##::::::: ######::: ########::
//  #########: ##.....:::: ##::........: ##.... ##: #########: ##. ####: ##:::: ##: ##::::::: ##...:::: ##.. ##:::
//  ##.... ##: ##::::::::: ##::::::::::: ##:::: ##: ##.... ##: ##:. ###: ##:::: ##: ##::::::: ##::::::: ##::. ##::
//  ##:::: ##: ##::::::::'####:::::::::: ##:::: ##: ##:::: ##: ##::. ##: ########:: ########: ########: ##:::. ##:
// ..:::::..::..:::::::::....:::::::::::..:::::..::..:::::..::..::::..::........:::........::........::..:::::..::
///
/// Begin of thread handler
///
#define Thread_Begin()                                                                             \
    kmmcf::Thread_t* __thread = kmmcf::Thread::_::thread_cur;                                      \
    switch (__thread->__GetAddr())                                                                 \
    {                                                                                              \
        case 0:;

///
/// End of thread handler
///
#define Thread_End()                                                                               \
    default:                                                                                       \
        __thread->__End();                                                                         \
        return;                                                                                    \
        }

///
/// Yield of thread handler
///
#define Thread_Yield()                                                                             \
    __thread->__Yield(__LINE__);                                                                   \
    return case __LINE__:;

///
/// Release current thread handler
///
#define Thread_Release() Thread_Yield()

///
/// delay current thread handler
/// @param delay[uint32_t] ticks for delay
///
#define Thread_Delay(delay)                                                                        \
    do                                                                                             \
    {                                                                                              \
        __thread->__Wait(delay);                                                                   \
        Thread_Yield();                                                                            \
    } while (0)

///
/// sleep current thread handler
/// @param sleep[uint32_t] ticks for sleep
///
#define Thread_Sleep(sleep) Thread_Delay(sleep)

///
/// wait time for current thread handler
/// @param ticks[uint32_t] ticks for wait
///
#define Thread_WaitFor(ticks) Thread_Delay(ticks)

///
/// wait event for thread
///
#define Thread_Wait(event, mask, timeout)                                                          \
    do                                                                                             \
    {                                                                                              \
        __thread->__Wait(event, mask, timeout);                                                    \
        Thread_Yield();                                                                            \
    } while (0)

///
/// Wait thread join
///
#define Thread_Join(th, timoeut)                                                                   \
    do                                                                                             \
    {                                                                                              \
        __thread->__Wait(th, timeout);                                                             \
        Thread_Yield();                                                                            \
    } while (0)

///
/// Is handler wakeup by timeout?
/// @return [true] timeout
/// @return [false] not timeout
///
#define Thread_IsTimeout() (__thread->__IsTimeout())

#endif /* KMMCF_THREAD_H */