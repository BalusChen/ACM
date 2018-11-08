/*
 * =====================================================================================
 *
 *       Filename:  swap_nodes_in_pairs.cc
 *
 *    Description:  Given a linked list, swap every two adjacent nodes and return its head
 *                  Example:
 *                          Input:  1->2->3->4
 *                          Output: 2->1->4->3
 *                  Your algorithm should use only constant space. You may not modify the
 *                  values in the list, only nodes itself can be changed.
 *                  The length of the list can be odd or even.
 *
 *        Version:  1.0
 *        Created:  09/27/2017 09:53:53 PM
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

ListNode* CreateList(const std::vector<int> ivec){
	auto head = new ListNode(*ivec.begin());
	auto temp = head;
	for(auto it = ivec.begin() + 1; it != ivec.end(); ++it){
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

ListNode* SwapPairs(ListNode *head){
	if(head == nullptr || head->next == nullptr){
		return head;
	}
	auto pre = new ListNode(0);
	pre->next = head;
	auto cur = head;
	auto ret = head->next;
	/*
	 * case1: the number of the node in the list is even
	 *        as cur moves, it will be nullptr
	 * case2: the number of the node in the list is odd
	 *        as cur moves to the last pair, there will be only one node left,
	 *        and then just return.
	 */
	while(cur != nullptr && cur->next != nullptr){
		pre->next = cur->next;
		cur->next = pre->next->next;
		pre->next->next = cur;
		pre = cur;
		cur = cur->next;
	}
	return ret;
}

/*
 * A better solution:
 * Pointer-pointer pp points to the pointer to the current node. So at first,
 * pp points to head, and later it points to the next field of ListNode.
 * Additional, for convenience and clarity, pointers cur and next point to 
 * the current node and the next node
 *
 * We need to go frome *pp == a -> b -> (b->next) to *pp == b -> a -> (b->next). 
 * The first three lines inside the loop do that, setting those three pointers
 * (from right to left). The fourth line moves pp to the next pair.
 */

ListNode* SwapPairs2(ListNode *head){
	ListNode **pp = &head, *a, *b;
	while((a = *pp) && (b = a->next)){
		a->next = b->next;
		b->next = a;
		*pp = b;
		pp = &(a->next);
	}
	return head;
}

int main()
{
	auto list1 = CreateList({1,2,3,4});
	auto list2 = CreateList({1,2});
	auto list3 = CreateList({1,2,3});
	auto list4 = CreateList({1});

	/*
	PrintList(SwapPairs(list1));
	PrintList(SwapPairs(list2));
	PrintList(SwapPairs(list3));
	PrintList(SwapPairs(list4));
	*/
	PrintList(SwapPairs2(list1));
	PrintList(SwapPairs2(list2));
	PrintList(SwapPairs2(list3));
	PrintList(SwapPairs2(list4));
}
