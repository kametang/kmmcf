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
#include <kmmcf/assert.h>
#include <kmmcf/thread.h>

#if THREAD_TIMEOUT
uint32_t th_tou_stamp;
uint32_t th_tou_ticks;

#define Th_Before()                                                                                \
    do                                                                                             \
    {                                                                                              \
        th_tou_stamp = kmmcf::Tick::Get();                                                         \
    } while (0)

#define Th_After(thread)                                                                           \
    do                                                                                             \
    {                                                                                              \
        th_tou_ticks = kmmcf::Tick::Get() - th_tou_stamp;                                          \
        if (th_tou_ticks >= kmmcf::Tick::MS(THREAD_TIMEOUT))                                       \
        {                                                                                          \
            thread->log.Error(                                                                     \
                "[TH/%s/WARN] %u us", thread->name, th_tou_stamp* CFG_TICK_INTERVAL);              \
        }                                                                                          \
    } while (0)

#else
#define Th_Before(...)
#define Th_After(...)
#endif

namespace kmmcf
{
    namespace _
    {
        List::List_t<Thread_t> thread_list();
        Thread_t*              thread_cur = NULL;
    }    // namespace _


    Thread_t::Thread_t(const char* name, void (*handler)(void) = NULL) :
        Node_t(), status(), wakeup(), timeout(), name(name), log()
    {
        this->handler = handler;
        this->status.Set(Thread::STATUS::STOPPED);
    }

    void Thread_t::SetHandler(void (*handler)(void))
    {
        Assert(handler);
        this->handler = handler;
        this->log.Debug("[TH/%s] = %p", this->name, this->handler);
    }

    void Thread_t::Start(void)
    {
        Assert(handler);
        if (this->isFree())
        {
            this->event = NULL;
            this->addr  = 0;
            this->status.Clear().Set(Thread::STATUS::RUN);
            Thread::_::thread_list.InsertTail(*this);
            this->log.Info("[TH/%s] start", this->name);
        }
    }

    void Thread_t::Stop(void)
    {
        if (!this->isFree())
        {
            this->free();
            this->status.Clear().Set(Thread::STATUS::STOPPED);
            this->log.Info("[TH/%s] stop", this->name);
        }
    }

    void Thread_t::__Wait(Event_t* event, uint32_t mask, uint32_t timeout)
    {
        this->event      = event;
        this->event_mask = mask;
        this->ticks      = timeout;
        this->timeout.ReCount();
        this->status.Clear().Set(Thread::STATUS::WAIT);
    }

    void Thread_t::__Execute(void)
    {
        // is wait?
        this->wakeup.Clear().Set(Thread::WAKEUP::NORMAL);
        if (this->status.IsSet(Thread::STATUS::WAIT))
        {
            // check event
            if (this->event != NULL && this->event->IsAny(this->event_mask))
            {
                this->wakeup.Clear().Set(Thread::WAKEUP::WAIT);
            }
            else if (this->timeout.IsDone(this->ticks))
            {
                this->wakeup.Clear().Set(Thread::WAKEUP::TIMEOUT);
            }
            else
            {
                return;
            }

            this->status.Clear().Set(Thread::STATUS::RUN);
        }

        // run
        Assert(this->handler);
        Th_Before();
        this->handler();
        Th_After(this);

        // is stop?
        if (this->status.IsSet(Thread::STATUS::STOPPED))
        {
            this->Stop();
        }
    }

}    // namespace kmmcf
