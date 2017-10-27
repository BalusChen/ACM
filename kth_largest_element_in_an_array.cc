/*
 * =====================================================================================
 *
 *       Filename:  kth_largest_element_in_an_array.cc
 *
 *    Description:  Find the Kth largest element in an unsorted array.
 *                  Note that it is the Kth largest element in the sorted order, 
 *                  not the Kth distinct element.
 *                  For example:
 *                              Given [3,2,1,5,6,4] and k = 2, return 5
 *                  Note:
 *                       You may assume k is always valid, 1 <=k <= array's length.
 *
 *        Version:  1.0
 *        Created:  10/27/2017 02:04:30 PM
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
#include <queue>
#include <utility>


/*
 * use "hole and percolate down" rather than "compare and swap" to avoid swapping.
 */
void percolate_down(std::vector<int>&ivec, int hole) {
	int tmp = std::move(ivec[hole]);
	int child = hole;
	for (; hole * 2 + 1 <= ivec.size() - 1; hole = child) {//node has at least one son
		child = hole * 2 + 1;
		if (child < ivec.size() -1 && ivec[child] < ivec[child + 1]) {//node has two sons and left son < right son
			++ child;
		}
		if (ivec[child] < tmp) {
			break;
		}
		ivec[hole] = std::move(ivec[child]);//the hole moves down
	}
	ivec[hole] = std::move(tmp);
}
/*
 * build a max-heap
 * percolate_down from the first node which has child up to root to maintain "Heap-Order Property"
 */

void build_max_heap(std::vector<int> &ivec) {
	for (int i = (ivec.size() - 1) /2; i >= 0; --i) {
		percolate_down(ivec, i);
	}
}

void extract_max(std::vector<int> &ivec, int &ret) {
	ret = std::move(ivec[0]);
	ivec[0] = ivec[ivec.size() - 1];
	if (ivec.size() != 1) {//in case that there are only one element in the array
		ivec.pop_back();
	}
	percolate_down(ivec, 0);
}

int findKthLargest(std::vector<int> &nums, int k) {
	build_max_heap(nums);
	int ret;
	for (int i = 0; i < k; ++i) {
		extract_max(nums, ret);
	}
	return ret;
}

void show(const std::vector<int> &ivec) {
	for (auto c : ivec) {
		std::cout << c << "  ";
	}
	std::cout << '\n';
}

/*
 * Solution2:
 * We can also use standard priority_queue to solve the problem for priority_queue is nicely implemented to be max-heap
 */

int findKthLargest2(std::vector<int> &nums, int k) {
	std::priority_queue<int> pq;
	for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
		pq.push(*it);
	}
	for (int i = 0; i < k - 1; ++i) {
		pq.pop();
	}
	return pq.top();
}

int main()
{
	std::vector<int> ivec0 {3, 2, 1, 5, 6, 4};
	std::cout << "the second biggest element is: " << findKthLargest2(ivec0, 2) << std::endl;
	build_max_heap(ivec0);
	std::cout << "the second biggest element is: " << findKthLargest(ivec0, 2) << std::endl;

	std::vector<int> ivec1 {-1, 2, 0};
	std::cout << "the second biggest element is: " << findKthLargest2(ivec1, 2) << std::endl;
	build_max_heap(ivec1);
	std::cout << "the second biggest element is: " << findKthLargest(ivec1, 2) << std::endl;

	std::vector<int> ivec2 {2, 7, 3, 34, 17, 34, -3};
	std::cout << "the third biggest element is: " << findKthLargest2(ivec2, 3) << std::endl;
	build_max_heap(ivec2);
	std::cout << "the third biggest element is: " << findKthLargest(ivec2, 3) << std::endl;

	std::vector<int> ivec3 {1};
	std::cout << "the biggest element is: " << findKthLargest2(ivec3, 1) << std::endl;
	build_max_heap(ivec3);
	std::cout << "the biggest element is: " << findKthLargest(ivec3, 1) << std::endl;

	std::vector<int> ivec4 {13, 34 ,17, 34, 7};
	std::cout << "the fourth biggest element is: " << findKthLargest2(ivec4, 4) << std::endl;
	build_max_heap(ivec4);
	std::cout << "the fourth biggest element is: " << findKthLargest(ivec4, 4) << std::endl;

	std::vector<int> ivec5 {-3, 7, -3, -34, 29, 100, 37, 9, 17, 51};
	std::cout << "the seventh biggest element is: " << findKthLargest2(ivec5, 7) << std::endl;
	build_max_heap(ivec5);
	std::cout << "the seventh biggest element is: " << findKthLargest(ivec5, 7) << std::endl;
}
