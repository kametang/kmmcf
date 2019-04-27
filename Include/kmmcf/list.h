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
        ///
        /// hidden
        ///
        namespace _
        {
            ///
            /// Base of list
            /// @tparam T final type of node
            ///
            template<class T> class List_Base_t
            {
                private:
                T *prev;
                T *next;

                protected:
                ///
                /// Insert node to next of current
                /// @param node node
                ///
                void insertHead(List_Base_t *node);

                ///
                /// Insert node to prev of current
                /// @param node node
                ///
                void insertTail(List_Base_t *node);

                ///
                /// Is node free?
                /// @return [true] free
                /// @return [false] belong to list
                ///
                bool isFree(void)
                {
                    return this->prev == this;
                }

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
        /// @tparam T final type for node
        ///
        template<class T> class Node_t : private _::List_Base_t<T>
        {
            friend class List_t<T>;

            public:
            ///
            /// construct
            ///
            Node_t(void) : List_Base_t() {}

            ///
            /// Get next of node
            /// @return node
            ///
            T *GetNext(void)
            {
                return this->next;
            }

            ///
            /// Get prev of node
            /// @return node
            ///
            T *GetPrev(void)
            {
                return this->prev;
            }

            ///
            /// Is node free?
            /// @return [true] node is free
            /// @return [false] node is belong to a list
            ///
            bool IsFree(void)
            {
                return this->isFree();
            }

            ///
            /// Free node object
            ///
            /// delete node from current list
            ///
            void Free(void);

            ///
            /// Insert a node to next of this
            /// @param node node
            ///
            void InsertNext(Node_t &node)
            {
                this->insertHead(node);
            }

            ///
            /// Insert a node to prev of this
            /// @param node node
            ///
            void InsertPrev(Node_t &node)
            {
                this->insertTail(node);
            }
        };


        ///
        /// List object
        /// @tparam T final type for node
        ///
        template<class T> class List_t : private _::List_Base_t<T>
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
                return this->next;
            }

            ///
            /// Get last node of list
            /// @return node
            ///
            T *GetLast(void)
            {
                return this->prev;
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
            void InsertHead(Node_t &node)
            {
                this->insertHead(node);
            }

            ///
            /// Insert node as last element of list
            /// @param node node
            ///
            void InsertTail(Node_t &node)
            {
                this->insertTail(node);
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
    for ((iter) = (list).GetHead(); (iter) != &(list); (iter) = (iter)->GetNext())

#endif /* KMMCF_LIST_H */