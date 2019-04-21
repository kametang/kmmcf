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
#ifndef KMMCF_ARCH_HOLTEK_H
#define KMMCF_ARCH_HOLTEK_H

#include "arch_def.h"

//
// '########::'#######:::'#######:::'#######:::::'##:::::::::'##:'##:::::::::::'##:::
//  ##.....::'##.... ##:'##.... ##:'##.... ##::'####::::::::'##:: ##:::'##:::'####:::
//  ##:::::::..::::: ##:..::::: ##:..::::: ##::.. ##:::::::'##::: ##::: ##:::.. ##:::
//  #######:::'#######:::'#######:::'#######::::: ##::::::'##:::: ##::: ##::::: ##:::
// ...... ##:'##::::::::'##:::::::::...... ##:::: ##:::::'##::::: #########:::: ##:::
// '##::: ##: ##:::::::: ##::::::::'##:::: ##:::: ##::::'##::::::...... ##::::: ##:::
// . ######:: #########: #########:. #######:::'######:'##::::::::::::: ##:::'######:
// :......:::.........::.........:::.......::::......::..::::::::::::::..::::......::
//

#if defined(USE_HT32F52231_41) || defined(HT32F52241) || defined(HT32F52231)                       \
    || (CFG_MCU == __MCU_HT32F52241) || (CFG_MCU == __MCU_HT32F52231)

#undef NO_MCU

#undef USE_HT32F52231_41
#define USE_HT32F52231_41

#define HT_M0

#define HSI_8

#endif /* HT32F52231, HT32F52241 */

#endif /* KMMCF_ARCH_HOLTEK_H */