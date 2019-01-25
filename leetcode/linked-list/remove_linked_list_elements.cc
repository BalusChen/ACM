/*
 * =====================================================================================
 *
 *       Filename:  remove_linked_list_elements.cc
 *
 *    Description:  Remove all elements from a linked list of integers that have the 
 *                  value val.
 *                  Example:
 *                         Given: 1->2->6->3->4->5->6, val=6
 *                         Return: 1-2->3->4->5
 *
 *        Version:  1.0
 *        Created:  09/27/2017 02:06:37 PM
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
	ListNode(int i) :
		data(i) { }
};
//create linked list for my test
ListNode* CreateList(const std::vector<int> ivec){
	auto head = new ListNode(*ivec.cbegin());
	auto temp = head;
	for(auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it){
		temp->next = new ListNode(*it);
		temp = temp->next;
	}
	return head;
}

//print the result
void PrintList(ListNode *head){
	auto temp = head;
	while(temp != nullptr){
		std::cout << temp->data << "   ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

ListNode* RemoveElements(ListNode *head, int val){
	//in case that the first element is to be deleted
	auto pre_head = new ListNode(val +1);
	pre_head->next = head;
	auto slow = pre_head;
	auto fast = pre_head->next;
	while(fast != nullptr){
		if(fast->data == val){//find the deletion
			slow->next = fast->next;
			fast = fast->next;
		}else{// move to the next place
			slow = slow->next;
			fast = fast->next;
		}
	}
	return pre_head->next;
}

/*
 * My code is too verbose.
 * I needn't have used both "slow" and "fast".
 * Here is a consise solution.
 */

ListNode* RemoveElements2(ListNode *head, int val){
	ListNode *pre_head = new ListNode(val + 1);
	pre_head->next = head;
	auto current = pre_head;
	while(current != nullptr){
		if(current->next != nullptr && current->next->data == val){
			current->next = current->next->next;
		}else{
			current = current->next;
		}
	}
	return pre_head->next;
}
int main()
{
	auto list1 = CreateList({1,2,6,3,4,5,6});
	auto list2 = CreateList({1});
	auto list3 = CreateList({3,7,3,9,7,3,3});
	PrintList(RemoveElements(list1,6));
	PrintList(RemoveElements(list2,1));
	PrintList(RemoveElements(list3,3));
	PrintList(RemoveElements(nullptr,3));
	/*
	PrintList(RemoveElements2(list1,6));
	PrintList(RemoveElements2(list2,2));
	PrintList(RemoveElements2(list3,3));
	PrintList(RemoveElements2(nullptr,3));
	*/
}
