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
#ifndef KMMCF_ARCH_HOLTEK_M0_H
#define KMMCF_ARCH_HOLTEK_M0_H

#include "arch_def.h"

// '########::'#######:::'#######:::'#######::::'#####:::::::::::::'#######::::'#####:::
//  ##.....::'##.... ##:'##.... ##:'##.... ##::'##.. ##:::::::::::'##.... ##::'##.. ##::
//  ##:::::::..::::: ##:..::::: ##:..::::: ##:'##:::: ##::::::::::..::::: ##:'##:::: ##:
//  #######:::'#######:::'#######:::'#######:: ##:::: ##:::::::::::'#######:: ##:::: ##:
// ...... ##:'##::::::::'##::::::::'##:::::::: ##:::: ##:::::::::::...... ##: ##:::: ##:
// '##::: ##: ##:::::::: ##:::::::: ##::::::::. ##:: ##:::::::::::'##:::: ##:. ##:: ##::
// . ######:: #########: #########: #########::. #####:::'#######:. #######:::. #####:::
// :......:::.........::.........::.........::::.....::::.......:::.......:::::.....::::
#if defined(USE_HT32F52220_30) || defined(HT32F52220) || defined(HT32F52230)
#ifndef USE_HT32F52220_30
#define USE_HT32F52220_30
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########::'#######:::'#######:::'#######:::::'##::::::::::::'##:::::::::::'##:::
//  ##.....::'##.... ##:'##.... ##:'##.... ##::'####:::::::::::: ##:::'##:::'####:::
//  ##:::::::..::::: ##:..::::: ##:..::::: ##::.. ##:::::::::::: ##::: ##:::.. ##:::
//  #######:::'#######:::'#######:::'#######::::: ##:::::::::::: ##::: ##::::: ##:::
// ...... ##:'##::::::::'##:::::::::...... ##:::: ##:::::::::::: #########:::: ##:::
// '##::: ##: ##:::::::: ##::::::::'##:::: ##:::: ##::::::::::::...... ##::::: ##:::
// . ######:: #########: #########:. #######:::'######:'#######::::::: ##:::'######:
// :......:::.........::.........:::.......::::......::.......::::::::..::::......::
#if defined(USE_HT32F52231_41) || defined(HT32F52231) || defined(HT32F52241)
#ifndef USE_HT32F52231_41
#define USE_HT32F52231_41
#endif

#define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########::'#######:::'#######:::'#######:::::'##::::::::::::'##:::::::::::'##:::
//  ##.....::'##.... ##:'##.... ##:'##.... ##::'####:::::::::::: ##:::'##:::'####:::
//  ##:::::::..::::: ##:..::::: ##:..::::: ##::.. ##:::::::::::: ##::: ##:::.. ##:::
//  #######:::'#######:::'#######:::'#######::::: ##:::::::::::: ##::: ##::::: ##:::
// ...... ##:'##:::::::::...... ##::...... ##:::: ##:::::::::::: #########:::: ##:::
// '##::: ##: ##::::::::'##:::: ##:'##:::: ##:::: ##::::::::::::...... ##::::: ##:::
// . ######:: #########:. #######::. #######:::'######:'#######::::::: ##:::'######:
// :......:::.........:::.......::::.......::::......::.......::::::::..::::......::
#if defined(USE_HT32F52331_41) || defined(HT32F52331) || defined(HT32F52341)
#ifndef USE_HT32F52331_41
#define USE_HT32F52331_41
#endif

#define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (48)

#endif

// '########::'#######:::'#######::'##:::::::::'#######:::::::::::'########::'#######::
//  ##.....::'##.... ##:'##.... ##: ##:::'##::'##.... ##:::::::::: ##.....::'##.... ##:
//  ##:::::::..::::: ##:..::::: ##: ##::: ##::..::::: ##:::::::::: ##:::::::..::::: ##:
//  #######:::'#######:::'#######:: ##::: ##:::'#######::::::::::: #######:::'#######::
// ...... ##:'##:::::::::...... ##: #########:'##:::::::::::::::::...... ##:'##::::::::
// '##::: ##: ##::::::::'##:::: ##:...... ##:: ##:::::::::::::::::'##::: ##: ##::::::::
// . ######:: #########:. #######:::::::: ##:: #########:'#######:. ######:: #########:
// :......:::.........:::.......:::::::::..:::.........::.......:::......:::.........::
#if defined(USE_HT32F52342_52) || defined(HT32F52342) || defined(HT32F52352)
#ifndef USE_HT32F52342_52
#define USE_HT32F52342_52
#endif

#define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (48)

#endif

// '########::'#######:::'#######::'##:::::::::'#######:::::::::::'########::'#######::
//  ##.....::'##.... ##:'##.... ##: ##:::'##::'##.... ##:::::::::: ##.....::'##.... ##:
//  ##:::::::..::::: ##:..::::: ##: ##::: ##::..::::: ##:::::::::: ##:::::::..::::: ##:
//  #######:::'#######:::'#######:: ##::: ##:::'#######::::::::::: #######:::'#######::
// ...... ##:'##::::::::'##:::::::: #########::...... ##::::::::::...... ##::...... ##:
// '##::: ##: ##:::::::: ##::::::::...... ##::'##:::: ##::::::::::'##::: ##:'##:::: ##:
// . ######:: #########: #########::::::: ##::. #######::'#######:. ######::. #######::
// :......:::.........::.........::::::::..::::.......:::.......:::......::::.......:::
#if defined(USE_HT32F52243_53) || defined(HT32F52243) || defined(HT32F52253)
#ifndef USE_HT32F52243_53
#define USE_HT32F52243_53
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########::'#######:::'#######:::'#######::
//  ##.....::'##.... ##:'##.... ##:'##.... ##:
//  ##::::::: ##:::: ##:..::::: ##: ##::::..::
//  #######::: #######:::'#######:: ########::
// ...... ##:'##.... ##:'##:::::::: ##.... ##:
// '##::: ##: ##:::: ##: ##:::::::: ##:::: ##:
// . ######::. #######:: #########:. #######::
// :......::::.......:::.........:::.......:::
#if defined(USE_HT32F5826) || defined(HT32F5826)
#ifndef USE_HT32F5826
#define USE_HT32F5826
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// ::'#####:::::'#####:::::'#####::::'#######::
// :'##.. ##:::'##.. ##:::'##.. ##::'##.... ##:
// '##:::: ##:'##:::: ##:'##:::: ##: ##:::: ##:
//  ##:::: ##: ##:::: ##: ##:::: ##:: #######::
//  ##:::: ##: ##:::: ##: ##:::: ##:'##.... ##:
// . ##:: ##::. ##:: ##::. ##:: ##:: ##:::: ##:
// :. #####::::. #####::::. #####:::. #######::
// ::.....::::::.....::::::.....:::::.......:::
#if defined(USE_HT32F0008) || defined(HT32F0008)
#ifndef USE_HT32F0008
#define USE_HT32F0008
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########:::'#####::::'#######:::'#######::::'#####:::::::::::::'#######::::'#####:::
//  ##.....:::'##.. ##::'##.... ##:'##.... ##::'##.. ##:::::::::::'##.... ##::'##.. ##::
//  ##:::::::'##:::: ##:..::::: ##:..::::: ##:'##:::: ##::::::::::..::::: ##:'##:::: ##:
//  #######:: ##:::: ##::'#######:::'#######:: ##:::: ##:::::::::::'#######:: ##:::: ##:
// ...... ##: ##:::: ##:'##::::::::'##:::::::: ##:::: ##:::::::::::...... ##: ##:::: ##:
// '##::: ##:. ##:: ##:: ##:::::::: ##::::::::. ##:: ##:::::::::::'##:::: ##:. ##:: ##::
// . ######:::. #####::: #########: #########::. #####:::'#######:. #######:::. #####:::
// :......:::::.....::::.........::.........::::.....::::.......:::.......:::::.....::::
#if defined(USE_HT32F50220_30) || defined(HT32F50220) || defined(HT32F50230)
#ifndef USE_HT32F50220_30
#define USE_HT32F50220_30
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########:::'#####::::'#######:::'#######:::::'##::::::::::::'##:::::::::::'##:::
//  ##.....:::'##.. ##::'##.... ##:'##.... ##::'####:::::::::::: ##:::'##:::'####:::
//  ##:::::::'##:::: ##:..::::: ##:..::::: ##::.. ##:::::::::::: ##::: ##:::.. ##:::
//  #######:: ##:::: ##::'#######:::'#######::::: ##:::::::::::: ##::: ##::::: ##:::
// ...... ##: ##:::: ##:'##:::::::::...... ##:::: ##:::::::::::: #########:::: ##:::
// '##::: ##:. ##:: ##:: ##::::::::'##:::: ##:::: ##::::::::::::...... ##::::: ##:::
// . ######:::. #####::: #########:. #######:::'######:'#######::::::: ##:::'######:
// :......:::::.....::::.........:::.......::::......::.......::::::::..::::......::
#if defined(USE_HT32F50231_41) || defined(HT32F50231) || defined(HT32F50241)
#ifndef USE_HT32F50231_41
#define USE_HT32F50231_41
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########::'#######:::'#######::'##::::::::'##:::::::::::::::::'########:'##::::::::
//  ##.....::'##.... ##:'##.... ##: ##:::'##:: ##:::'##::::::::::: ##.....:: ##:::'##::
//  ##:::::::..::::: ##:..::::: ##: ##::: ##:: ##::: ##::::::::::: ##::::::: ##::: ##::
//  #######:::'#######:::'#######:: ##::: ##:: ##::: ##::::::::::: #######:: ##::: ##::
// ...... ##:'##:::::::::...... ##: #########: #########::::::::::...... ##: #########:
// '##::: ##: ##::::::::'##:::: ##:...... ##::...... ##:::::::::::'##::: ##:...... ##::
// . ######:: #########:. #######:::::::: ##:::::::: ##::'#######:. ######:::::::: ##::
// :......:::.........:::.......:::::::::..:::::::::..:::.......:::......:::::::::..:::
#if defined(USE_HT32F52344_54) || defined(HT32F52344) || defined(HT32F52354)
#ifndef USE_HT32F52344_54
#define USE_HT32F52344_54
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// ::'#####:::::'#####:::::'#####::::'#######::
// :'##.. ##:::'##.. ##:::'##.. ##::'##.... ##:
// '##:::: ##:'##:::: ##:'##:::: ##: ##::::..::
//  ##:::: ##: ##:::: ##: ##:::: ##: ########::
//  ##:::: ##: ##:::: ##: ##:::: ##: ##.... ##:
// . ##:: ##::. ##:: ##::. ##:: ##:: ##:::: ##:
// :. #####::::. #####::::. #####:::. #######::
// ::.....::::::.....::::::.....:::::.......:::
#if defined(USE_HT32F0006) || defined(HT32F0006)
#ifndef USE_HT32F0006
#define USE_HT32F0006
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########::'#######:::'#######::'########:'########:::::::::::'#######::'########:
//  ##.....::'##.... ##:'##.... ##: ##.....:: ##..  ##::::::::::'##.... ##: ##..  ##:
//  ##:::::::..::::: ##:..::::: ##: ##:::::::..:: ##:::::::::::: ##::::..::..:: ##:::
//  #######:::'#######:::'#######:: #######::::: ##::::::::::::: ########::::: ##::::
// ...... ##:'##:::::::::...... ##:...... ##::: ##:::::::::::::: ##.... ##::: ##:::::
// '##::: ##: ##::::::::'##:::: ##:'##::: ##::: ##:::::::::::::: ##:::: ##::: ##:::::
// . ######:: #########:. #######::. ######:::: ##:::::'#######:. #######:::: ##:::::
// :......:::.........:::.......::::......:::::..::::::.......:::.......:::::..::::::
#if defined(USE_HT32F52357_67) || defined(HT32F52357) || defined(HT32F52367)
#ifndef USE_HT32F52357_67
#define USE_HT32F52357_67
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// :'#######::'########::'#######::'##::::::::::'#####:::
// '##.... ##: ##.....::'##.... ##: ##:::'##:::'##.. ##::
//  ##::::..:: ##:::::::..::::: ##: ##::: ##::'##:::: ##:
//  ########:: #######:::'#######:: ##::: ##:: ##:::: ##:
//  ##.... ##:...... ##:'##:::::::: #########: ##:::: ##:
//  ##:::: ##:'##::: ##: ##::::::::...... ##::. ##:: ##::
// . #######::. ######:: #########::::::: ##:::. #####:::
// :.......::::......:::.........::::::::..:::::.....::::
#if defined(USE_HT32F65240) || defined(HT32F65240)
#ifndef USE_HT32F65240
#define USE_HT32F65240
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########:'########::'#######:::'#######:::::'##::::::::::::'##:::::::::::'##:::
//  ##.....:: ##..  ##:'##.... ##:'##.... ##::'####:::::::::::: ##:::'##:::'####:::
//  ##:::::::..:: ##:::..::::: ##:..::::: ##::.. ##:::::::::::: ##::: ##:::.. ##:::
//  #######::::: ##:::::'#######:::'#######::::: ##:::::::::::: ##::: ##::::: ##:::
// ...... ##::: ##::::::...... ##::...... ##:::: ##:::::::::::: #########:::: ##:::
// '##::: ##::: ##:::::'##:::: ##:'##:::: ##:::: ##::::::::::::...... ##::::: ##:::
// . ######:::: ##:::::. #######::. #######:::'######:'#######::::::: ##:::'######:
// :......:::::..:::::::.......::::.......::::......::.......::::::::..::::......::
#if defined(USE_HT32F57331_41) || defined(HT32F57331) || defined(HT32F57341)
#ifndef USE_HT32F57331_41
#define USE_HT32F57331_41
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif

// '########:'########::'#######::'##:::::::::'#######:::::::::::'########::'#######::
//  ##.....:: ##..  ##:'##.... ##: ##:::'##::'##.... ##:::::::::: ##.....::'##.... ##:
//  ##:::::::..:: ##:::..::::: ##: ##::: ##::..::::: ##:::::::::: ##:::::::..::::: ##:
//  #######::::: ##:::::'#######:: ##::: ##:::'#######::::::::::: #######:::'#######::
// ...... ##::: ##::::::...... ##: #########:'##:::::::::::::::::...... ##:'##::::::::
// '##::: ##::: ##:::::'##:::: ##:...... ##:: ##:::::::::::::::::'##::: ##: ##::::::::
// . ######:::: ##:::::. #######:::::::: ##:: #########:'#######:. ######:: #########:
// :......:::::..:::::::.......:::::::::..:::.........::.......:::......:::.........::
#if defined(USE_HT32F57342_52) || defined(HT32F57342) || defined(HT32F57352)
#ifndef USE_HT32F57342_52
#define USE_HT32F57342_52
#endif

// #define HOLTEK_M0
#define CLK_HSI (8)
#define CLK_MHZ (40)

#endif


// :'######::'##::::'##::'######::'####::'######::
// '##... ##: ###::'###:'##... ##:. ##::'##... ##:
//  ##:::..:: ####'####: ##:::..::: ##:: ##:::..::
//  ##::::::: ## ### ##:. ######::: ##::. ######::
//  ##::::::: ##. #: ##::..... ##:: ##:::..... ##:
//  ##::: ##: ##:.:: ##:'##::: ##:: ##::'##::: ##:
// . ######:: ##:::: ##:. ######::'####:. ######::
// :......:::..:::::..:::......:::....:::......:::

#if defined(HOLTEK_M0)

#undef NO_MCU

typedef enum IRQn
{
    /****** Cortex-M0+ Processor Exceptions Numbers ******************************** */
    NonMaskableInt_IRQn = -14, /*!< 2 Non Maskable Interrupt */
    HardFault_IRQn      = -13, /*!< 3 Cortex-M0+ Hard Fault Interrupt */
    SVCall_IRQn         = -5,  /*!< 11 Cortex-M0+ SV Call Interrupt */
    PendSV_IRQn         = -2,  /*!< 14 Cortex-M0+ Pend SV Interrupt */
    SysTick_IRQn        = -1,  /*!< 15 Cortex-M0+ System Tick Interrupt */

    /******  HT32 Specific Interrupt Numbers *************************************** */
    LVD_BOD_IRQn = 0, /*!< Low voltage & Brown-out detection interrupt */
#if !defined(USE_HT32F52220_30)
    RTC_IRQn = 1, /*!< RTC Wake-up Interrupt */
#endif
    FLASH_IRQn    = 2, /*!< FLASH global Interrupt */
    EVWUP_IRQn    = 3, /*!< EXTI Event Wake-up & WAKEUP pin Interrupt */
    EXTI0_1_IRQn  = 4, /*!< EXTI0-1 Line detection Interrupt */
    EXTI2_3_IRQn  = 5, /*!< EXTI2-3 Line detection Interrupt */
    EXTI4_15_IRQn = 6, /*!< EXTI4-15 Line detection Interrupt */
#if defined(USE_HT32F52342_52) || defined(USE_HT32F5826) || defined(USE_HT32F52344_54)
    COMP_IRQn = 7, /*!< Comparator global Interrupt */
#endif
#if !defined(USE_HT32F0008)
    ADC_IRQn = 8, /*!< ADC Interrupt */
#endif
#if !defined(USE_HT32F52220_30) && !defined(USE_HT32F0008) && !defined(USE_HT32F50220_30)
    MCTM0_IRQn = 10, /*!< Motor Control Timer0 interrupt */
#endif
#if defined(USE_HT32F2243_53)
    I2C2_IRQn = 9, /*!< I2C2 global Interrupt */
#endif
#if defined(USE_HT32F52342_52) || defined(USE_HT32F5826)
    GPTM1_IRQn = 11, /*!< General-Purpose Timer1 Interrupt */
#endif
    GPTM0_IRQn = 12, /*!< General-Purpose Timer0 Interrupt */
#if !defined(USE_HT32F0008) && !defined(USE_HT32F50220_30) && !defined(USE_HT32F50231_41)
    SCTM0_IRQn = 13, /*!< Single Channel Timer0 Interrupt */
    SCTM1_IRQn = 14, /*!< Single Channel Timer1 Interrupt */
#endif
#if defined(USE_HT32F52231_41) || defined(USE_HT32F52331_41) || defined(USE_HT32F52243_53)
    SCTM2_IRQn = 15, /*!< Single Channel Timer2 Interrupt */
    SCTM3_IRQn = 16, /*!< Single Channel Timer3 Interrupt */
#endif
#if defined(USE_HT32F0008) || defined(USE_HT32F50220_30) || defined(USE_HT32F50231_41)
    PWM0_IRQn = 15, /*!< PWM Timer0 Interrupt */
    PWM1_IRQn = 16, /*!< PWM Timer1 Interrupt */
#endif
    BFTM0_IRQn = 17, /*!< Basic Function Timer0 Interrupt */
#if !defined(USE_HT32F52220_30) && !defined(USE_HT32F50220_30)
    BFTM1_IRQn = 18, /*!< Basic Function Timer1 Interrupt */
#endif
    I2C0_IRQn = 19, /*!< I2C0 global Interrupt */
#if !defined(USE_HT32F52220_30) && !defined(USE_HT32F0008) && !defined(USE_HT32F50220_30)          \
    && !defined(USE_HT32F52344_54)
    I2C1_IRQn = 20, /*!< I2C1 global Interrupt */
#endif
    SPI0_IRQn = 21, /*!< SPI0 global Interrupt */
#if !defined(USE_HT32F52220_30) && !defined(USE_HT32F0008)
    SPI1_IRQn = 22, /*!< SPI1 global Interrupt */
#endif
#if !defined(USE_HT32F50220_30) && !defined(USE_HT32F52344_54)
    USART0_IRQn = 23, /*!< USART0 global Interrupt */
#endif
#if defined(USE_HT32F52342_52) || defined(USE_HT32F52243_53) || defined(USE_HT32F5826)
    USART1_IRQn = 24, /*!< USART1 global Interrupt */
#endif
    UART0_IRQn = 25, /*!< UART0 global Interrupt */
#if !defined(USE_HT32F52220_30) && !defined(USE_HT32F0008)
    UART1_IRQn = 26, /*!< UART1 global Interrupt */
#endif
#if defined(USE_HT32F52331_41) || defined(USE_HT32F52342_52) || defined(USE_HT32F5826)
    SCI_IRQn = 27, /*!< Smart Card Interface Interrupt */
#endif
#if defined(USE_HT32F52342_52) || defined(USE_HT32F5826)
    I2S_IRQn = 28, /*!< I2S global Interrupt */
#endif
#if defined(USE_HT32F52243_53)
    UART2_IRQn = 27, /*!< UART2 global Interrupt */
    UART3_IRQn = 28, /*!< UART3 global Interrupt */
#endif
#if defined(USE_HT32F0008)
    AES_IRQn = 28, /*!< AES global Interrupt */
#endif
#if defined(USE_HT32F52331_41) || defined(USE_HT32F52342_52) || defined(USE_HT32F5826)             \
    || defined(USE_HT32F0008) || defined(USE_HT32F52344_54)
    USB_IRQn = 29, /*!< USB interrupt */
#endif
#if defined(USE_HT32F52342_52) || defined(USE_HT32F52243_53) || defined(USE_HT32F5826)             \
    || defined(USE_HT32F0008) || defined(USE_HT32F52344_54)
    PDMACH0_1_IRQn = 30, /*!< PDMA channel 0-1 interrupt */
    PDMACH2_5_IRQn = 31, /*!< PDMA channel 2-5 interrupt */
#endif
} IRQn_Type;

#define __MPU_PRESENT 0          /*!< MPU present or not */
#define __VTOR_PRESENT 1         /*!< VTOR present or not */
#define __NVIC_PRIO_BITS 2       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig 0 /*!< Set to 1 if different SysTick Config is used */

#include <cmsis/core_cm0plus.h>

#endif

#endif /* KMMCF_ARCH_HOLTEK_M0_H */