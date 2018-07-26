#ifndef PRINT_H__
#define PRINT_H__

#include <iostream>
#include <vector>
#include "listnode.h"

template<typename T>
void PrintVector (const std::vector<T> &items) {
    for (const auto &c : items) {
        std::cout << c << " ";
    }
    std::cout << '\n';
}

void PrintLinkedList (const ListNode *head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << '\n';
}

#endif /* PRINT_H__ */
