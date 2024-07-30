//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Aniket Sedhai on 7/18/24.
//

#include <iostream>
#include "DoublyLinkedList.h"

int main(void)
{
    int N = 1000;
    std::srand(time(nullptr));
    
    DoublyLinkedList test_linked_list_class;
    
    std::cout << "performing push_front() with 10 random values between 0 and 999." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        test_linked_list_class.push_front(rand() % N);
    }
    
    std::cout << test_linked_list_class;
    
    int size_of_linked_list = test_linked_list_class.size();
    
    std::cout << "performing pop_front() past the size of the linked list." << std::endl;
    for (int i = 0; i < size_of_linked_list + 1; ++i)
    {
        test_linked_list_class.pop_front();
    }
    
    if (test_linked_list_class.empty())
    {
        std::cout << "The linked list is empty!" << std::endl;
    }
    else
    {
        std::cout << "The linked list is not empty!" << std::endl;
    }
    
    std::cout << test_linked_list_class;
    
    std::cout << "performing push_front() with 10 random values between 0 and 999." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        test_linked_list_class.push_front(rand() % N);
    }
    
    if (test_linked_list_class.empty())
    {
        std::cout << "The linked list is empty!" << std::endl;
    }
    else
    {
        std::cout << "The linked list is not empty!" << std::endl;
    }
    
    std::cout << test_linked_list_class;

    
    test_linked_list_class.insert(2, 150);
    
    std::cout << test_linked_list_class;
    
    std::cout << "test_linked_list_class[2] = " << test_linked_list_class[2] << std::endl;
    
    std::cout << "test_linked_list_class[100] = " <<test_linked_list_class[100] << std::endl;
    
    std::cout << "test_linked_list_class[-54] = " <<test_linked_list_class[-54] << std::endl;
    
    std::cout << "Erased 2nd, -20nd, and 150th position elements." << std::endl;
    test_linked_list_class.erase(2);
    test_linked_list_class.erase(-20);
    test_linked_list_class.erase(150);
    
    std::cout << test_linked_list_class;
    
    std::cout << "Inserting 245 at index 9." << std::endl;
    test_linked_list_class.insert(9, 245);
    
    std::cout << test_linked_list_class;
    
    if (test_linked_list_class.find(245) != -1)
    {
        std::cout << "245 found at index " << test_linked_list_class.find(245) << std::endl;
    }
    else
    {
        std::cout << "245 not found" << std::endl;
    }
    
    if (test_linked_list_class.find(630) != -1)
    {
        std::cout << "630 found at index " << test_linked_list_class.find(245) << std::endl;
    }
    else
    {
        std::cout << "630 not found" << std::endl;
    }

    
    return 0;
}
