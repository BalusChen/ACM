/*
 * =====================================================================================
 *
 *       Filename:  AddTwoNumbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/14/2017 10:44:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom 
 *   Organization:  iEach
 *
 * =====================================================================================
 */
#include <iostream>
#include <initializer_list>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* addTwoNumbers(ListNode *l1,ListNode *l2){
	ListNode preHead(0);
	ListNode *ret = &preHead;
	int extra = 0;
	while(l1 != nullptr || l2 != nullptr || extra != 0){
		int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + extra;
		ret->next = new ListNode(sum % 10);
		ret = ret->next;
		extra = sum / 10;
		l1 = (l1 == nullptr) ? l1 : l1->next;
		l2 = (l2 == nullptr) ? l2 : l2->next;
	}
	return preHead.next;
}

void printList(ListNode *list){
	while(list != nullptr){
		cout<<list->val<<"  ";
		list = list->next;
	}
	cout<<'\n';
}

ListNode* createList(initializer_list<int> ilist){
	ListNode preHead(0);
	ListNode *ret = & preHead;
	for(auto it = ilist.begin(); it != ilist.end(); ++it){
		ret->next = new ListNode(*it);
		ret = ret->next;
	}
	return preHead.next;
}

int main()
{
	ListNode *l1 = createList({2,4,3});
	ListNode *l2 = createList({5,6,4});
	printList(addTwoNumbers(l1,l2));
	ListNode *l3 = createList({5});
	ListNode *l4 = createList({5});
	printList(addTwoNumbers(l3,l4));
	ListNode *l5 = createList({3,6,9});
	ListNode *l6 = createList({7,8,3,4});
	printList(addTwoNumbers(l5,l6));
}
