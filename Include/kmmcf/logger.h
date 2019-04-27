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
#ifndef KMMCF_LOGGER_H
#define KMMCF_LOGGER_H

#include "typedef.h"

namespace kmmcf
{
    ///
    /// logger namespace
    ///
    namespace Logger
    {
        ///
        /// levels
        ///
        enum Level
        {
            ///
            /// error level
            ///
            ERR = (1 << 1),
            ///
            /// critical level
            ///
            CRIT = (1 << 2),
            ///
            /// information level
            ///
            INFO = (1 << 3),
            ///
            /// debug level
            ///
            DBG = (1 << 4),
        };    // enum class Level

        // prototype
        class Logger_t;

        ///
        /// hidden namespace
        ///
        namespace _
        {
            constexpr uint32_t OPT_EN = (1 << 0);
#if defined(RELEASE)
            constexpr uint32_t OPT_DEFAULT = Level::ERR | Level::CRIT;
#else
            constexpr uint32_t OPT_DEFAULT = OPT_EN | Level::ERR | Level::CRIT;
#endif


            ///
            /// Logger options
            ///
            class Option_t
            {
                friend class Logger_t;

                private:
                ///
                /// options
                ///
                uint32_t options;

                public:
                ///
                /// Construct a new Option_t object
                /// @param options options
                ///
                Option_t(uint32_t options = OPT_DEFAULT)
                {
                    this->options = options;
                }

                ///
                /// enable logger
                ///
                void Enable(void)
                {
                    this->options |= OPT_EN;
                }

                ///
                /// disable logger
                ///
                void Disable(void)
                {
                    this->options &= ~OPT_EN;
                }

                ///
                /// enable levels
                /// @param levels collection of levels
                ///
                void EnableLevels(uint32_t levels)
                {
                    this->options |= levels;
                }

                ///
                /// disable levels
                /// @param levels colleciton of levels
                ///
                void DisableLevels(uint32_t levels)
                {
                    this->options &= ~levels;
                }
            };    // class Option_t

        }    // namespace _

        ///
        /// global config for logger
        ///
        extern _::Option_t Config;

        ///
        /// Logger type
        ///
        class Logger_t : private _::Option_t
        {
            private:
            ///
            /// Basic logger
            /// @param level level of logger
            /// @param format format as printf
            /// @param args args
            ///
            void Log(Level level, const char *format, va_list args);

            public:
            ///
            /// Construct a new Logger_t object
            /// @param options logger options
            ///
            Logger_t(uint32_t options = _::OPT_DEFAULT) : Option_t(options) {}

            ///
            /// Error logger
            /// @param format format as printf
            /// @param ... args
            ///
            void Error(const char *format, ...);

            ///
            /// Critical logger
            /// @param format format as printf
            /// @param ... args
            ///
            void Crit(const char *format, ...);

            ///
            /// Information logger
            /// @param format format as printf
            /// @param ... args
            ///
            void Info(const char *format, ...);

            ///
            /// Debug logger
            /// @param format format as printf
            /// @param ... args
            ///
            void Debug(const char *format, ...);
        };    // class Logger_t

    }    // namespace Logger

    ///
    /// Application logger
    ///
    extern Logger::Logger_t Log;

};    // namespace kmmcf

#endif /* KMMCF_LOGGER_H */