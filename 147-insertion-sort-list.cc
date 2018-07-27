#include "include/make-linkedlist.h"
#include "include/print.h"

ListNode* insertionSortList(ListNode *head) {
    // 链表为空或者链表只有一个元素，直接返回
    if (!head || !head->next) {
        return head;
    }

    head->next = insertionSortList(head->next);
    /*
    auto ret = head;
    bool head_has_changed = false;
    while (head->next && (head->val > head->next->val)) {
        ListNode *next = head->next;
        head->next = next->next;
        next->next = head;
        if (!head_has_changed) {
            ret = head;
            head_has_changed = true;
        }
    }
    PrintLinkedList(ret);
    */
    auto prev = head;
    auto next = head->next;
    while (next && (head->val > next->val)) {
        prev = next;
        next = next->next;
    }
    auto ret = head;
    if (prev != head) {
        ret = head->next;
        prev->next = head;
        head->next = next;
    }

    return ret;

}

int main() {
    ListNode *list1 = MakeLinkedList();
    ListNode *list2 = MakeLinkedList();
    ListNode *list3 = MakeLinkedList();

    std::cout << "list1 before sort:  ";
    PrintLinkedList(list1);
    list1 = insertionSortList(list1);
    std::cout << "list1 after sort:   ";
    PrintLinkedList(list1);

    std::cout << "list2 before sort:  ";
    PrintLinkedList(list2);
    list2 = insertionSortList(list2);
    std::cout << "list2 after sort:   ";
    PrintLinkedList(list2);

    std::cout << "list3 before sort:  ";
    PrintLinkedList(list3);
    list3 = insertionSortList(list3);
    std::cout << "list3 after sort:   ";
    PrintLinkedList(list3);
}
