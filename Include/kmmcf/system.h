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
#ifndef KMMCF_SYSTEM_H
#define KMMCF_SYSTEM_H

#include "typedef.h"

namespace kmmcf
{
    ///
    /// system status
    ///
    namespace System
    {
        ///
        /// Interrupt
        ///
        namespace Interrupt
        {
            ///
            /// hidden
            ///
            namespace _
            {
                ///
                /// interrupt depth
                ///
                extern volatile uint32_t interrupt_depth;
            }    // namespace _

            ///
            /// begin of interrupt handler
            ///
            static inline void Begin(void)
            {
                _::interrupt_depth++;
            }

            ///
            /// end of interrupt handler
            ///
            static inline void End(void)
            {
                _::interrupt_depth--;
            }

            ///
            /// Is system in interrupt handler?
            /// @return [true] in interrupt
            /// @return [false] in main
            ///
            static inline bool Is(void)
            {
                return (_::interrupt_depth > 0);
            }
        }    // namespace Interrupt

    }    // namespace System

}    // namespace kmmcf


#endif /* KMMCF_SYSTEM_H */