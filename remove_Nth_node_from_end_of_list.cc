/*
 * =====================================================================================
 *
 *       Filename:  remove_Nth_node_from_end_of_list.cc
 *
 *    Description:  Given a linked list, remove the Nth node from the end of the list
 *                  and return its head.
 *                  Example:
 *                          Input: 1->2->3->4->5, and n = 2
 *                          Output: 1->2->3->5
 *                  Note:
 *                       1.Given n will always be valid
 *                       2.Try to do this in one pass
 *
 *        Version:  1.0
 *        Created:  11/01/2017 08:18:51 PM
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

/*
 * Original Version Of Mine 
 * The solution is not good.
 * It runs slowly and walks for 2 pass
 */
/*
ListNode* removeNthFromEnd(ListNode *head, int n) {
	if (head == nullptr) {
		return nullptr;
	}

	int count = 0;
	auto p = head;
	auto pre = head;
	//the number of nodes in the link-list
	while(p != nullptr) {
		p = p->next;
		++ count;
	}

	//if delete the head node
	if (n == count) {
		p = head->next;
		delete head;
		return p;
	}

	p = head;
	while(count != n) {
		if (count == n+1) {
			pre = p;
			p = p->next;
		} else {
			p = p->next;
		}
		-- count;
	}
	pre->next = p->next;
	delete p;
	return head;
}
*/

/*
 * A fast and concise solution copied from leetcode
 * Why use pointer to pointer?
 * Here is a good explaination: http://blogread.cn/it/article/6243?f=wb
 */
ListNode* removeNthFromEnd(ListNode *head, int n) {
	auto t1 = &head;
	auto t2 = head;
	for(int i = 1; i < n; ++i) {
		t2 = t2->next;
	}

	while(t2->next != nullptr) {
		t1 = & ((*t1)->next);
		t2 = t2->next;
	}
	auto del = *t1;
	delete del;
	*t1 = (*t1)->next;//understand!
	return head;
}

int main()
{
	auto list1 = create_list({1,3,5,7,9});
	print(removeNthFromEnd(list1,2));

	auto list2 = create_list({1,3,5,7,9});
	print(removeNthFromEnd(list2,5));

	auto list3 = create_list({1,7,13,34,27,11});
	print(removeNthFromEnd(list3,3));

	auto list4 = create_list({7});
	print(removeNthFromEnd(list4,1));

	auto list5 = create_list({7,34});
	print(removeNthFromEnd(list5,1));
	
	auto list6 = create_list({34,7,51});
	print(removeNthFromEnd(list6,3));
}
