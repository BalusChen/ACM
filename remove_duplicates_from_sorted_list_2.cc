/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_sorted_list_2.cc
 *
 *    Description:  Given a sorted list, delete all nodes that have duplicate
 *                  numbers, leaving only distince numbers from the original list.
 *                  Example:
 *                          Given 1->2->3->3->4->4->5, return 1->2->5
 *                          Given 1->1->1->2->3, return 2->3
 *
 *        Version:  1.0
 *        Created:  10/31/2017 12:57:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
#include <initializer_list>

struct ListNode
{
	int data;
	ListNode *next;
	ListNode(int i, ListNode *n = nullptr) :
		data(i), next(n) { }
};

/*  Make Preparations and For Debugging */
ListNode* create_list(const std::initializer_list<int> &lst) {
	auto pre_head = new ListNode(0);//for convenience
	auto p = pre_head;
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		p->next = new ListNode(*it);
		p = p->next;
	}
	auto ret = pre_head->next;
	delete pre_head;
	return ret;
}

void print(ListNode *head) {
	auto p = head;
	while(p != nullptr) {
		std::cout << p->data << "  ";
		p = p->next;
	}
	std::cout << "\n-----------------------divider---------------------------\n";
}

ListNode* deleteDuplicates(ListNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	auto pre_head = new ListNode(head->data + 1);//for convience
	auto pre_dup = pre_head;
	pre_dup->next = head;
	ListNode *dup_beg = head;
	ListNode *dup_end = nullptr;
	ListNode *deletion = nullptr;
	while(dup_beg != nullptr) {
		dup_end = dup_beg->next;
		if (dup_end != nullptr && dup_end->data == dup_beg->data) {//find duplicate
			//detemine the duplicated range
			while(dup_end != nullptr && dup_end->data == dup_beg->data) {
				dup_end = dup_end->next;
			}
			//free the duplicates
			while(dup_beg != dup_end) {
				deletion = dup_beg;
				delete deletion;
				dup_beg = dup_beg->next;
			}
			pre_dup->next = dup_beg;
		} else {//duplicate not found, just move forward
			pre_dup = pre_dup->next;
			dup_beg = dup_beg->next;
		}
	}
	auto ret = pre_head->next;
	delete pre_head;
	return ret;
}

int main()
{
	auto list1 = create_list({1,1,1,2,2,3,4});
	print(deleteDuplicates(list1));

	auto list2 = create_list({1,1});
	print(deleteDuplicates(list2));
	
	auto list3 = create_list({1});
	print(deleteDuplicates(list3));

	auto list4 = create_list({1,3,4,7,7,7,13,13,34});
	print(deleteDuplicates(list4));
	
	auto list5 = create_list({3,3,4,7,11,13,14,14,34,51,51});
	print(deleteDuplicates(list5));

	auto list6 = create_list({});
	print(deleteDuplicates(list6));
}
