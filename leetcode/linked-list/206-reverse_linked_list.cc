/*
 * =====================================================================================
 *
 *       Filename:  reverse_linked_list.cc
 *
 *    Description:  Reverse a single linked list.
 *
 *        Version:  1.0
 *        Created:  09/28/2017 06:12:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

struct ListNode
{
	int data;
	ListNode *next;
	ListNode(int x) :
		data(x), next(nullptr) { }
};

ListNode* CreateList(const std::vector<int> &ivec){
	if(ivec.size() == 0){
		return nullptr;
	}
	auto head = new ListNode(*ivec.begin());
	auto temp = head;
	for(auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it){
		temp->next = new ListNode(*it);
		temp = temp->next;
	}
	return head;
}

void PrintList(ListNode *head){
	auto temp = head;
	while(temp != nullptr){
		std::cout << temp->data << "   ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
/*
 * My solution.
 * The idea is to reverse one node at a time to be the beginning of the list.
 */

ListNode* ReverseList(ListNode* head){
	if(head == nullptr || head->next == nullptr){
		return head;
	}
	auto pre = head;
	auto cur = head->next;
	auto h   = head;
	while(cur != nullptr){
		pre->next = cur->next;
		cur->next = h;
		h = cur;
		cur  = pre->next;
	}
	return h;
}

/*
 * Here is a more concise solution
 * Its idea is the same as mine.
 */

ListNode* ReverseList2(ListNode* head){
	ListNode *cur = head, *pre = nullptr, *temp;
	while(cur != nullptr){
		temp = cur->next;//record the next position of cur for iteration
		cur->next = pre;
		pre = cur;//record the head of the list so as to be inserted before
		cur = temp;// move to the next position
	}
	return pre;
}

/*
 * Here is a recurise version
 * But it's difficult for me to get full understanding.
 */
ListNode* ReverseList3(ListNode* head){
	if(!head || !(head->next)){
		return head;
	}
	auto res = ReverseList3(head->next);
	head->next->next = head;
	head->next = nullptr;
	return res;
}

int main()
{
	auto list1 = CreateList({1,2,3,4,5});
	auto list2 = CreateList({2,4,6,8,7});
	auto list3 = CreateList({3});
	auto list4 = CreateList({});
	/*
	PrintList(ReverseList(list1));
	PrintList(ReverseList(list2));
	PrintList(ReverseList(list3));
	PrintList(ReverseList(list4));
	*/
	/* 
	PrintList(ReverseList2(list1));
	PrintList(ReverseList2(list2));
	PrintList(ReverseList2(list3));
	PrintList(ReverseList2(list4));
	*/
	PrintList(ReverseList3(list1));
	PrintList(ReverseList3(list2));
	PrintList(ReverseList3(list3));
	PrintList(ReverseList3(list4));
}
