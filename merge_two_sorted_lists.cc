/*
 * =====================================================================================
 *
 *       Filename:  merge_two_sorted_lists.cc
 *
 *    Description:  Merge two sorted lists and return it as a new list. The new list 
 *                  should be made by splicing together the nodes of the first two lists
 *
 *        Version:  1.0
 *        Created:  09/29/2017 07:10:41 PM
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

/* My Solution */
ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr || l2 == nullptr) {
		return l1 == nullptr ? l2 : l1;
	}

	ListNode *pre_head = new ListNode(0);
	auto p = pre_head;//just for convenience in the "while loop" below
	while(l1 != nullptr || l2 != nullptr) {
		if (l1 != nullptr && l2 != nullptr) {
			if (l1->data < l2->data) {
				p->next = new ListNode(l1->data);
				l1 = l1->next;
			}else {
				p->next = new ListNode(l2->data);
				l2 = l2->next;
			}
		} else {
			p->next = new ListNode(l1 == nullptr ? l2->data : l1->data);
			l1 = l1 == nullptr ? l1 : l1->next;//if the node is null, it needn't move forward
			l2 = l2 == nullptr ? l2 : l2->next;
		}
		p = p->next;
	}
	p = pre_head->next;
	delete pre_head;
	return p;

}


/* A Recursive-Version Solution */
ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	if (l1->data < l2->data) {
		l1->next = MergeTwoLists(l1->next, l2);
		return l1;
	} else {
		l2->next = MergeTwoLists(l2->next, l1);
		return l2;
	}
}

int main()
{
	auto list1 = create_list({1,3,5,7,9});
	auto list2 = create_list({2,4,6,8,10,12,14,16});
	print(MergeTwoLists(list1,list2));
	
	auto list3 = create_list({2});
	auto list4 = create_list({1});
	print(MergeTwoLists(list3,list4));

	auto list5 = create_list({7,13,19,21});
	auto list6 = create_list({3,21,33,34});
	print(MergeTwoLists(list5,list6));

	auto list7 = create_list({11,22,34,37,51,74,79,87,97});
	auto list8 = create_list({37});
	print(MergeTwoLists(list7,list8));
}
