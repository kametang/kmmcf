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
#ifndef KMMCF_EVENT_H
#define KMMCF_EVENT_H

#include "typedef.h"

namespace kmmcf
{
    ///
    /// Event object
    ///
    class Event_t
    {
        private:
        ///
        /// event value
        ///
        uint32_t event;

        public:
        ///
        /// Construct
        ///
        Event_t(void)
        {
            this->event = 0;
        }

        ///
        /// Set event bit
        /// @param bit bit
        /// @return event for chain opt
        ///
        Event_t& Set(uint8_t bit)
        {
            this->event |= (1 << bit);
            return *this;
        }

        ///
        /// reset event bit
        /// @param bit bit
        /// @return event for chain opt
        ///
        Event_t& Reset(uint8_t bit)
        {
            this->event &= ~(1 << bit);
            return *this;
        }

        ///
        /// Is bit set?
        /// @param bit bit
        /// @return [true] set
        /// @return [false] reset
        ///
        bool IsSet(uint8_t bit)
        {
            return ((this->event & (1 << bit)) > 0);
        }

        ///
        /// Set event mask
        /// @param mask mask
        /// @return event for chain opt
        ///
        Event_t& SetMask(uint32_t mask)
        {
            this->event |= mask;
            return *this;
        }

        ///
        /// reset event mask
        /// @param mask mask
        /// @return event for chain opt
        ///
        Event_t& ResetMask(uint32_t mask)
        {
            this->event &= ~mask;
            return *this;
        }

        ///
        /// Is any bit of event set?
        /// @param mask mask
        /// @return [true] at least one bit set
        /// @return [false] no bit set
        ///
        bool IsAny(uint32_t mask)
        {
            return ((this->event & mask) > 0);
        }

        ///
        /// Is all bit of event set?
        /// @param mask mask
        /// @return [true] all bit in mask set
        /// @return [false] not all bit in mask set
        ///
        bool IsAll(uint32_t mask)
        {
            return ((this->event & mask) == mask);
        }

        ///
        /// overwrite event
        /// @param event event
        /// @return event for chain opt
        ///
        Event_t& Write(uint32_t event)
        {
            this->event = event;
            return *this;
        }

        ///
        /// get event
        /// @return event
        ///
        uint32_t Read(void)
        {
            return this->event;
        }

        ///
        /// clear events
        /// @return event for chain opt
        ///
        Event_t& Clear(void)
        {
            return this->Write(0);
        }
    };
}    // namespace kmmcf


#endif /* KMMCF_EVENT_H */