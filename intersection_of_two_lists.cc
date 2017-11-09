/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_two_lists.cc
 *
 *    Description:  Write a program to find the node at which the intersection of two
 *                  singly linked list begins.
 *                  Example:
 *                          A: a1 -> a2
 *                                            -> c1 -> c2 -> c3 begin to intersect at c1
 *                          B: b1 -> b2 -> b3
 *                  Notes:
 *                        1.If the two linked lists have no intersection at all, return
 *                          nullptr.
 *                        2.The linked lists must retain their original structure after
 *                          the function returns.
 *                        3.You may assume there are no cycles anywhere in the entire linked
 *                          structuer
 *                        4.Your code should preferably run in O(n) time and use only O(1)
 *                          memory.
 *
 *        Version:  1.0
 *        Created:  09/29/2017 06:58:49 PM
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
#include <initializer_list>

struct ListNode
{
	int data;
	ListNode *next;
	ListNode(int i) :
		data(i), next(nullptr) { }
};

ListNode* create_list(const std::initializer_list<int> &ilst, ListNode* &end) {
	ListNode *pre_head = new ListNode(0);
	auto p = pre_head;
	for (auto it = ilst.begin(); it != ilst.end(); ++it) {
		p->next = new ListNode(*it);
		p = p->next;
	}
	end = p;
	p = pre_head->next;
	delete pre_head;
	return p;
}
void print(ListNode *);

std::pair<ListNode*, ListNode*> create_lists(const std::initializer_list<int> &ilist1, const std::initializer_list<int> &ilist2, const std::initializer_list<int> &common) {
	ListNode *end = nullptr;
	auto inter = create_list(common, end);
	auto head1 = create_list(ilist1, end);
	end->next = inter;
	auto head2 = create_list(ilist2, end);
	end->next = inter;
	return {head1, head2};
}


void print(ListNode *inter) {
	auto p = inter;
	while(p != nullptr) {
		std::cout << p->data << "  ";
		p = p->next;
	}
	std::cout << "\n--------------------divider----------------------\n";
}

/*
 * A Simple Solution From LeetCode
 * Note that list1 intersecting with list2 means that the nodes(not node->data but node) of list1 and list2 
 * will be the same at some node.
 * The key is that p1 walks the same length as p2 does.
 */

ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
	ListNode *p1 = head1;
	ListNode *p2 = head2;

	if (p1 == nullptr || p2 == nullptr) return nullptr;

	while (p1 != nullptr && p2 != nullptr && p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;

		/*
		 * Any time they collide or reach end together without colliding
		 * they return any one of the pointers.
		 */
		if (p1 == p2) return p1;
		
		/*
		 * If one of them reaches the end earlier then reuse it
		 * by moving it to the beginning of the other list.
		 * Once both of them go through reassigning
		 * they will be equidistant from the collision point.
		 */
		if (p1 == nullptr) p1 = head2;
		if (p2 == nullptr) p2 = head1;
	}
	return p1;
}


int main()
{
	auto pair1 = create_lists({1,3,5,7}, {2,4,6,8}, {7,34,51});
	auto list11 = pair1.first;
	auto list12 = pair1.second;
	print(getIntersectionNode(list11, list12));

	auto pair2 = create_lists({1,3,5,7}, {2,4,6,8}, { });
	auto list21 = pair2.first;
	auto list22 = pair2.second;
	print(getIntersectionNode(list21, list22));

	auto pair3 = create_lists({1,3,5,7,9,11}, {2,4,6,8}, { });
	auto list31 = pair3.first;
	auto list32 = pair3.second;
	print(getIntersectionNode(list31, list32));

	auto pair4 = create_lists({1,3,5,7,9,11}, {2,4,6,8,20,15,666,777,999}, {34,51});
	auto list41 = pair4.first;
	auto list42 = pair4.second;
	print(getIntersectionNode(list41, list42));
}
