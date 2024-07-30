//
//  DoublyLinkedList.h
//  DoublyLinkedList
//
//  Created by Aniket Sedhai on 7/18/24.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <iostream>

class DoubleNode
{
public:
    DoubleNode(signed short data,
               DoubleNode* next_ptr = nullptr,
               DoubleNode* prev_ptr = nullptr);
    signed short data;
    DoubleNode* prev_node_ptr;
    DoubleNode* next_node_ptr;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    
    ~DoublyLinkedList();
    
    void push_front(signed short value);
    
    void pop_front(void);
    
    friend std::ostream& operator <<(std::ostream& ostr, const DoublyLinkedList& rhs);
    
    unsigned short operator[](int index);
    
    bool empty();
    
    int size(void) const;
    
    void insert(int positionIndex, signed short value);
    
    void erase(int positionIndex);
    
    int find(signed short value);
    
private:

    DoubleNode* head_node_ptr;
};

#endif /* DoublyLinkedList_h */
