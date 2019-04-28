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
#ifndef KMMCF_TICK_H
#define KMMCF_TICK_H

#include "typedef.h"
#include <kmmcf_conf.h>

namespace kmmcf
{
    ///
    /// Tick namespace
    ///
    namespace Tick
    {
        ///
        /// hidden
        ///
        namespace _
        {
            ///
            /// 1 ms = ? tick
            ///
            constexpr uint32_t TICK_PER_MS = 1000 / CFG_TICK_INTERVAL;

            ///
            /// global tick
            ///
            extern volatile uint32_t tick;
        }    // namespace _

        ///
        /// Get current tick
        /// @return tick
        ///
        static inline uint32_t Get(void)
        {
            return _::tick;
        }

        ///
        /// Get ticks from ms
        /// @param ms ms
        /// @return ticks
        ///
        constexpr uint32_t MS(uint32_t ms)
        {
            return ms * _::TICK_PER_MS;
        }

        ///
        /// Get ticks from second
        /// @param sec second
        /// @return ticks
        ///
        constexpr uint32_t SEC(uint32_t sec)
        {
            return sec * MS(1000);
        }

        ///
        /// Get ticks from minutes
        /// @param min minutes
        /// @return ticks
        ///
        constexpr uint32_t MIN(uint32_t min)
        {
            return min * SEC(60);
        }

        ///
        /// Get ticks from hours
        /// @param hour hours
        /// @return ticks
        ///
        constexpr uint32_t HOUR(uint32_t hour)
        {
            return hour * MIN(60);
        }

    }    // namespace Tick

    ///
    /// hidden
    ///
    namespace _
    {
        ///
        /// Initialize
        ///
        namespace Init
        {
            ///
            /// Tick initialize
            ///
            void Tick(void);
        }    // namespace Init

    }    // namespace _


}    // namespace kmmcf

// '########::'########:'########::::'###::::'##::::'##:'##:::::::'########:
//  ##.... ##: ##.....:: ##.....::::'## ##::: ##:::: ##: ##:::::::... ##..::
//  ##:::: ##: ##::::::: ##::::::::'##:. ##:: ##:::: ##: ##:::::::::: ##::::
//  ##:::: ##: ######::: ######:::'##:::. ##: ##:::: ##: ##:::::::::: ##::::
//  ##:::: ##: ##...:::: ##...:::: #########: ##:::: ##: ##:::::::::: ##::::
//  ##:::: ##: ##::::::: ##::::::: ##.... ##: ##:::: ##: ##:::::::::: ##::::
//  ########:: ########: ##::::::: ##:::: ##:. #######:: ########:::: ##::::
// ........:::........::..::::::::..:::::..:::.......:::........:::::..:::::

void SysTick_Handler(void);


#endif /* KMMCF_TICK_H */