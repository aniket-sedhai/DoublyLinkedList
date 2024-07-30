//
//  DoublyLinkedList.cpp
//  DoublyLinkedList
//
//  Created by Aniket Sedhai on 7/18/24.
//

#include <stdio.h>
#include "DoublyLinkedList.h"

DoubleNode::DoubleNode(signed short data,
    DoubleNode* prev_ptr,
    DoubleNode* next_ptr)
    : data(data),
    prev_node_ptr(prev_ptr),
    next_node_ptr(next_ptr)
{
    
}

DoublyLinkedList::DoublyLinkedList():
    head_node_ptr(nullptr)
{
    //do nothing
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (empty() == false)
    {
        pop_front();
    }
}

void DoublyLinkedList::push_front(signed short value)
{
    DoubleNode* new_node = new DoubleNode(value);
    
    if (empty() == true)
    {
        head_node_ptr = new_node;
    }
    else
    {
        new_node->next_node_ptr = head_node_ptr;
        head_node_ptr->prev_node_ptr = new_node;
        head_node_ptr = new_node;
    }
}

void DoublyLinkedList::pop_front(void)
{
    if (empty() == false)
    {
        
        if (size() == 1)
        {
            delete head_node_ptr;
            head_node_ptr = nullptr;
        }
        else
        {
            DoubleNode* old_front_ptr = head_node_ptr;

            head_node_ptr = head_node_ptr->next_node_ptr;
            head_node_ptr->prev_node_ptr = nullptr;
            delete old_front_ptr;
        }
    }
}

std::ostream& operator <<(std::ostream& ostr, const DoublyLinkedList& rhs)
{
    DoubleNode* current_node_ptr = rhs.head_node_ptr;
    
    ostr << "Doubly Linked List: ";
    
    while(current_node_ptr != nullptr)
    {
        ostr << current_node_ptr->data << " | ";
        current_node_ptr = current_node_ptr->next_node_ptr;
    }
    
    ostr << std::endl;
    
    return ostr;
}

bool DoublyLinkedList::empty()
{
    return head_node_ptr == nullptr;
}

int DoublyLinkedList::size(void) const
{
    int size = 0;
    DoubleNode* current_node_ptr = head_node_ptr;
    while(current_node_ptr != nullptr)
    {
        ++size;
        current_node_ptr = current_node_ptr->next_node_ptr;
    }
    return size;
}

unsigned short DoublyLinkedList::operator[](int index)
{
    
    if ((index < 0) || (index >= size()))
    {
        return std::numeric_limits<signed short>::min();
    }

    DoubleNode* current_node_ptr = head_node_ptr;
    for (int i = 0; i < index; ++i)
    {
        current_node_ptr = current_node_ptr->next_node_ptr;
    }
    return current_node_ptr->data;
}

void DoublyLinkedList::insert(int positionIndex, signed short value)
{
    DoubleNode* new_node_ptr = new DoubleNode(value);
    if (empty() == true)
    {
        head_node_ptr = new_node_ptr;
        return;
    }
    else if (positionIndex <= 0)
    {
        new_node_ptr->next_node_ptr = head_node_ptr;
        head_node_ptr->prev_node_ptr = new_node_ptr;
        head_node_ptr = new_node_ptr;
    }
    else if ((positionIndex > 0))
    {
        DoubleNode* current_node_ptr = head_node_ptr;
        
        if (positionIndex >= size())
        {
            while (current_node_ptr->next_node_ptr != nullptr)
            {
                current_node_ptr = current_node_ptr->next_node_ptr;
            }
            
            current_node_ptr->next_node_ptr = new_node_ptr;
            new_node_ptr->prev_node_ptr = current_node_ptr;
        }
        else
        {
            for (int i = 0; i < positionIndex; ++i)
            {
                current_node_ptr = current_node_ptr->next_node_ptr;
            }
            
            current_node_ptr->prev_node_ptr->next_node_ptr = new_node_ptr;
            new_node_ptr->next_node_ptr = current_node_ptr;
            new_node_ptr->prev_node_ptr = current_node_ptr->prev_node_ptr;
        }
    }
}

void DoublyLinkedList::erase(int positionIndex)
{
    if (empty() == true)
    {
        return;
    }
    else if (positionIndex <= 0)
    {
        pop_front();
    }
    else if ((positionIndex > 0) && (positionIndex < size()))
    {
        DoubleNode* current_node_ptr = head_node_ptr;
        
        for (int i = 0; i < positionIndex; ++i)
        {
            current_node_ptr = current_node_ptr->next_node_ptr;
        }
        current_node_ptr->prev_node_ptr->next_node_ptr = current_node_ptr->next_node_ptr;
        current_node_ptr->next_node_ptr->prev_node_ptr = current_node_ptr->prev_node_ptr;
        delete current_node_ptr;
    }
}

int DoublyLinkedList::find(signed short value)
{
    DoubleNode* current_node_ptr = head_node_ptr;
    int index = 0;
    
    while (current_node_ptr != nullptr)
    {
        if (current_node_ptr->data == value)
            return index;
        current_node_ptr = current_node_ptr->next_node_ptr;
        ++index;
    }
    
    return -1;
}
