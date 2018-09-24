/*
 * =====================================================================================
 *
 *       Filename:  linked_list_cycle.cc
 *
 *    Description:  Given a linked list, determine if it has a cycle in it.
 *                  Follow up:
 *                            Can you solve it without using extra space?
 *
 *        Version:  1.0
 *        Created:  10/01/2017 07:15:09 PM
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
		data(i), next(nullptr) { }
};

/*
 * If index >= ivec.size(), there will be no cycle in the list created
 */

ListNode* CreateList(const std::vector<int> &ivec, int index){
	if(ivec.size() == 0){
		return nullptr;
	}
	auto head = new ListNode(*ivec.cbegin());
	auto temp = head;
	ListNode *cycle_begin = nullptr;
	if(index == 0){
		cycle_begin = head;
	}
	for(auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it){
		temp->next = new ListNode(*it);
		temp = temp->next;
		if(--index == 0){
			cycle_begin = temp;
		}
	}
	temp->next = cycle_begin;
}

/*
 * This solution is not mine.
 * I just adapt it from a java version to a C++ version.
 * The "slow" pointer moves step by step
 * The "fast" pointer moves two steps at a time
 * If there is a cycle in the list, "slow" and "fast" will meet at some point
 */
bool HasCycle(ListNode *head){
	if(head == nullptr || head->next == nullptr){
		return false;
	}
	auto slow = head;
	auto fast = head->next;
	while(fast->next != nullptr && fast->next->next != nullptr){
		if(fast == slow){
			return true;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}

int main()
{
	auto list1 = CreateList({1,3,5,7,9},0);
	auto list2 = CreateList({1,3,5,7,9},7);
	auto list3 = CreateList({1,3,5,7,9},4);
	auto list4 = CreateList({3},0);
	auto list5 = CreateList({},0);
	std::cout << (HasCycle(list1) ? "has cycle" : "doesn't have cycle") << std::endl;
	std::cout << (HasCycle(list2) ? "has cycle" : "doesn't have cycle") << std::endl;
	std::cout << (HasCycle(list3) ? "has cycle" : "doesn't have cycle") << std::endl;
	std::cout << (HasCycle(list4) ? "has cycle" : "doesn't have cycle") << std::endl;
	std::cout << (HasCycle(list5) ? "has cycle" : "doesn't have cycle") << std::endl;
}
