/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_sorted_list.cc
 *
 *    Description:  Given a sorted list, deleted all duplicates such that each element
 *                  appear only once.
 *                  Example:
 *                          Given 1->1->2, return 1->2
 *                          Given 1->1->2->3->3, return 1->2->3
 *
 *        Version:  1.0
 *        Created:  09/27/2017 01:30:23 PM
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
	ListNode(int x) :
		data(x), next(nullptr) { }
};

/* create a linked list for my tests  */
ListNode* CreateList(const std::initializer_list<int> &list){
	/* wrong
	ListNode it ( *list.begin());
	auto head = &it;
	*/
	auto head = new ListNode(*list.begin());
	auto temp = head;
	for(auto it = list.begin() + 1; it != list.end(); ++it){
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

ListNode* DeleteDuplicates(ListNode* head){
	if(head == nullptr || head->next == nullptr){
		return head;
	}
	auto slow = head;
	auto fast = head->next;
	while(true){
		//since the list has already been sorted, the duplicates must be continuous
		while(fast != nullptr && fast->data == slow->data){
			fast = fast->next;
		}
		slow->next = fast;
		// come to the end of the list
		if(fast == nullptr){
			break;
		}
		//move to the next place where the duplicates may occur 
		slow = slow->next;
		fast = fast->next;
	}
	return head;
}

int main()
{
	auto list1 = CreateList({1,1,2});
	auto list2 = CreateList({1,1,2,3,3,});
	auto list3 = CreateList({2,2,4,4,4,4,7,9,9,11});
	PrintList(DeleteDuplicates(list1));
	PrintList(DeleteDuplicates(list2));
	PrintList(DeleteDuplicates(list3));
}
