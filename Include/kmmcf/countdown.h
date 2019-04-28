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
#ifndef KMMCF_COUNTDOWN_H
#define KMMCF_COUNTDOWN_H

#include "tick.h"

namespace kmmcf
{
    ///
    /// countdown object
    ///
    class Cd_t
    {
        private:
        ///
        /// recount stamp
        ///
        uint32_t stamp;
        ///
        /// is active
        ///
        bool is_act;

        public:
        ///
        /// constructor
        ///
        Cd_t(void)
        {
            this->is_act = false;
        }

        ///
        /// activate and recount
        ///
        void ReCount(void)
        {
            this->is_act = true;
            this->stamp  = Tick::Get();
        }

        ///
        /// check is countdown is done, and deactive when done
        /// @param ticks ticks for compare
        /// @return [true] done and deactive
        /// @return [false] not done yet.
        ///
        bool IsDone(uint32_t ticks)
        {
            if (this->is_act && ((Tick::Get() - this->stamp) >= ticks))
            {
                this->is_act = false;
                return true;
            }
            return false;
        }

        ///
        /// deactive countdown
        ///
        void Stop(void)
        {
            this->is_act = false;
        }
    };
}    // namespace kmmcf


#endif /* KMMCF_COUNTDOWN_H */