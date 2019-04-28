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
#ifndef KMMCF_LIST_H
#define KMMCF_LIST_H

namespace kmmcf
{
    ///
    /// List namespace
    ///
    namespace List
    {
        // prototype

        template<class T> class List_t;
        template<class T> class Node_t;

        ///
        /// hidden
        ///
        namespace _
        {
            ///
            /// Base of list
            ///
            class List_Base_t
            {
                protected:
                ///
                /// Prev node
                ///
                List_Base_t *prev;

                ///
                /// Next node
                ///
                List_Base_t *next;

                ///
                /// Insert node to next of current
                /// @param node node
                ///
                void insertHead(List_Base_t &node);

                ///
                /// Insert node to prev of current
                /// @param node node
                ///
                void insertTail(List_Base_t &node);

                ///
                /// Is node free?
                /// @return [true] free
                /// @return [false] belong to list
                ///
                bool isFree(void)
                {
                    return this->prev == this;
                }

                ///
                /// Free node
                ///
                void free(void);

                public:
                ///
                /// Construct a new List_t object
                ///
                List_Base_t(void)
                {
                    this->prev = this;
                    this->next = this;
                }
            };    // class List_Base_t


        }    // namespace _


        ///
        /// Node object
        /// @tparam T type of final node
        ///
        template<class T> class Node_t : protected _::List_Base_t
        {
            friend class List_t;

            public:
            ///
            /// construct
            ///
            Node_t(void) : List_Base_t() {}

            ///
            /// Get next object
            /// @return
            ///
            T *__GetNext(void)
            {
                return (T *) this->next;
            }
        };

        ///
        /// List object
        /// @tparam T type of final node
        ///
        template<class T> class List_t : protected _::List_Base_t
        {
            public:
            ///
            /// Constructor
            ///
            List_t(void) : List_Base_t() {}

            ///
            /// Get first node of list
            /// @return node
            ///
            T *GetHead(void)
            {
                return (T *) this->next;
            }


            ///
            /// Get last node of list
            /// @return node
            ///
            T *GetLast(void)
            {
                return (T *) this->prev;
            }


            ///
            /// Is list empty?
            /// @return [true] empty
            /// @return [false] has node
            ///
            bool IsEmpty(void)
            {
                return this->next = this;
            }

            ///
            /// Insert node as first element of list
            /// @param node node
            ///
            void InsertHead(T &node)
            {
                this->insertHead(node);
            }


            ///
            /// Insert node as last element of list
            /// @param node node
            ///
            void InsertTail(T &node)
            {
                this->insertTail(node);
            }

            ///
            /// Is list end
            /// @param node node object
            /// @return [true] end
            /// @return [false] not end
            ///
            bool __IsEnd(T *node)
            {
                return this == node;
            }
        };

    }    // namespace List

}    // namespace kmmcf

///
/// Macro to iteration all node of list
/// @param iter node pointer for iteration
/// @param list list object
///
#define LIST_FOREACH(iter, list)                                                                   \
    for ((iter) = (list).GetHead(); list.__IsEnd(iter); (iter) = (iter)->__GetNext())

#endif /* KMMCF_LIST_H */