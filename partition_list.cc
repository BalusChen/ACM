/*
 * =====================================================================================
 *
 *       Filename:  partition_list.cc
 *
 *    Description:  Given a linked list and a value x, partition it such that all nodes
 *                  less than x come before nodes greater than or equal to x.
 *                  You should preserve the original relative order of the nodes in each
 *                  of the two partitions.
 *
 *        Version:  1.0
 *        Created:  10/02/2017 06:25:13 PM
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

ListNode* create_list(const std::vector<int> &ivec){
	auto head = new ListNode(*ivec.cbegin());
	auto temp = head;
	for(auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it){
		temp->next = new ListNode(*it);
		temp = temp->next;
	}
	return head;
}

void print(ListNode *head){
	auto temp = head;
	while(temp != nullptr){
		std::cout << temp->data << "   ";
		temp = temp->next;
	}
	std::cout << '\n';
}

/*
 * My Original Solution.
 * The Solution is not good.
 * It runs so slowly although it solves the problem
 * for there are many unnecessary define and delete statements in it.
 */
ListNode* partition(ListNode *head, int x){
	if (head == nullptr || head->next == nullptr) {
		return nullptr;
	}
	auto p = head;
	ListNode *lesser = new ListNode(0);
	auto less_end = lesser;
	ListNode *greater = new ListNode(0);
	auto greater_end = greater;

	while (p != nullptr) {
		if (p->data < x) {
			less_end->next = p;
			less_end = less_end->next;
		} else {
			greater_end->next = p;
			greater_end = greater_end->next;
		}
		p = p->next;
	}
	greater_end->next = nullptr;

	if(lesser->next == nullptr) {
		auto ret = greater->next;
		delete greater;
		return ret;
	} else {
		less_end->next = greater->next;
		delete greater;
		auto ret = lesser->next;
		delete lesser;
		return ret;
	}
}


/*
 * After revision.
 */
ListNode* Partition(ListNode *head, int x) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode node1(0), node2(0);
	auto p = head;
	auto p1 = &node1;
	auto p2 = &node2;
	while(p != nullptr) {
		if (p->data < x) {
			p1->next = p;
			p1 = p1->next;
		} else {
			p2->next = p;
			p2 = p2->next;
		}
		p = p->next;
	}
	p2->next = nullptr;
	p1->next = node2.next;
	return node1.next;
}


int main()
{
	auto list1 = create_list({1,4,3,2,2,5,2});
	auto list2 = create_list({3,7,21,7,8,34});
	auto list3 = create_list({1,1});
	auto list4 = create_list({2,1});
	print(Partition(list1, 3));
	print(Partition(list2, 13));
	print(Partition(list3, 0));
	print(Partition(list4, 1));
}
