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
#include <kmmcf/list.h>

namespace kmmcf
{
    namespace List
    {
        namespace _
        {
            // '########:::::'###:::::'######::'########:
            //  ##.... ##:::'## ##:::'##... ##: ##.....::
            //  ##:::: ##::'##:. ##:: ##:::..:: ##:::::::
            //  ########::'##:::. ##:. ######:: ######:::
            //  ##.... ##: #########::..... ##: ##...::::
            //  ##:::: ##: ##.... ##:'##::: ##: ##:::::::
            //  ########:: ##:::: ##:. ######:: ########:
            // ........:::..:::::..:::......:::........::
            void List_Base_t::insertHead(List_Base_t &node)
            {
                if (this->isFree())
                {
                    node.next       = this->next;
                    node.prev       = this;
                    node.next->prev = &node;
                    this->next      = &node;
                }
            }

            void List_Base_t::insertTail(List_Base_t &node)
            {
                if (this->isFree())
                {
                    node.next       = this;
                    node.prev       = this->prev;
                    node.prev->next = &node;
                    this->prev      = &node;
                }
            }

            void List_Base_t::free(void)
            {
                if (!this->isFree())
                {
                    this->prev->next = this->next;
                    this->next->prev = this->prev;
                    this->prev       = this;
                }
            }
        }    // namespace _
    }        // namespace List
}    // namespace kmmcf