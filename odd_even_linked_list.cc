/*
 * =====================================================================================
 *
 *       Filename:  odd_even_linked_list.cc
 *
 *    Description:  Given a singly linked list, group all odd nodes together followed by
 *                  the even nodes. Please note here we are talking about the node number
 *                  and not the value in the nodes.
 *                  You should try to do it in place. The program should run in O(1) space
 *                  complexity and O(nodes) time complexity.
 *                  Example:
 *                          Given: 1->2->3->4->5->NULL
 *                          Return: 1->3->5->2->4->NULL
 *                  Note:
 *                       The relative order inside both the even and odd groups should 
 *                       remain as it was in the input
 *                       The first node is considered odd, the second node even and so on...
 *
 *        Version:  1.0
 *        Created:  11/02/2017 03:27:28 PM
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
	ListNode(int i) :
		data(i), next(nullptr) { }
};

ListNode* create_list(const std::initializer_list<int> &ilst) {
	ListNode *pre_head = new ListNode(0);
	auto p = pre_head;
	for (auto it = ilst.begin(); it != ilst.end(); ++it) {
		p->next = new ListNode(*it);
		p = p->next;
	}
	p = pre_head->next;
	delete pre_head;
	return p;
}

void print(ListNode *head) {
	auto p = head;
	while(p != nullptr) {
		std::cout << p->data << "   ";
		p = p->next;
	}
	std::cout << "\n--------------------divider----------------------\n";
}


ListNode* oddEvenList(ListNode *head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	auto odd_end = head;
	auto even_beg = head->next;//for linking
	auto even_end = head->next;
	auto p = head->next->next;
	bool is_odd = true;
	while(p != nullptr) {
		if(is_odd) {
			odd_end->next = p;
			odd_end = odd_end->next;
			is_odd = false;//the next is not odd
		} else {
			even_end->next = p;
			even_end = even_end->next;
			is_odd = true;// the next is not even
		}
		p = p->next;
	}
	odd_end->next = even_beg;//link odd with even;
	even_end->next = nullptr;
	return head;
}


int main()
{
	auto list1 = create_list({1,2,3,4,5,6,7});
	print(oddEvenList(list1));

	auto list2 = create_list({2,1,4,3,6,5});
	print(oddEvenList(list2));

	auto list3 = create_list({4,5,6,7,8});
	print(oddEvenList(list3));

	auto list4 = create_list({1,3,4,5,7,9,6,34,13});
	print(oddEvenList(list4));
}
