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
#include <kmmcf/logger.h>

// :'######:::'##::::::::'#######::'########:::::'###::::'##:::::::
// '##... ##:: ##:::::::'##.... ##: ##.... ##:::'## ##::: ##:::::::
//  ##:::..::: ##::::::: ##:::: ##: ##:::: ##::'##:. ##:: ##:::::::
//  ##::'####: ##::::::: ##:::: ##: ########::'##:::. ##: ##:::::::
//  ##::: ##:: ##::::::: ##:::: ##: ##.... ##: #########: ##:::::::
//  ##::: ##:: ##::::::: ##:::: ##: ##:::: ##: ##.... ##: ##:::::::
// . ######::: ########:. #######:: ########:: ##:::: ##: ########:
// :......::::........:::.......:::........:::..:::::..::........::

kmmcf::Logger::_::Option_t kmmcf::Logger::Config(0xFFFFFFFF);
kmmcf::Logger::Logger_t    kmmcf::Log(0xFFFFFFFF);

// '##::::::::'#######:::'######::::'######:::'########:'########::
//  ##:::::::'##.... ##:'##... ##::'##... ##:: ##.....:: ##.... ##:
//  ##::::::: ##:::: ##: ##:::..::: ##:::..::: ##::::::: ##:::: ##:
//  ##::::::: ##:::: ##: ##::'####: ##::'####: ######::: ########::
//  ##::::::: ##:::: ##: ##::: ##:: ##::: ##:: ##...:::: ##.. ##:::
//  ##::::::: ##:::: ##: ##::: ##:: ##::: ##:: ##::::::: ##::. ##::
//  ########:. #######::. ######:::. ######::: ########: ##:::. ##:
// ........:::.......::::......:::::......::::........::..:::::..::
void kmmcf::Logger::Logger_t::Log(Level level, const char *format, va_list args)
{
    using _::OPT_EN;
    uint32_t options = Config.options & this->options;

    if ((options & OPT_EN) && (options & level))
    {
        vprintf(format, args);
        printf("\r\n");
    }
}

void kmmcf::Logger::Logger_t::Error(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    this->Log(Level::ERR, format, args);
    va_end(args);
}

void kmmcf::Logger::Logger_t::Crit(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    this->Log(Level::CRIT, format, args);
    va_end(args);
}

void kmmcf::Logger::Logger_t::Info(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    this->Log(Level::INFO, format, args);
    va_end(args);
}

void kmmcf::Logger::Logger_t::Debug(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    this->Log(Level::DBG, format, args);
    va_end(args);
}