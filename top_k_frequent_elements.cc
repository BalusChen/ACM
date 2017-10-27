/*
 * =====================================================================================
 *
 *       Filename:  top_k_frequent_elements.cc
 *
 *    Description:  Given a non-empty array of integers, return the K most requent elements.
 *                  For example:
 *                              Given [1,1,1,2,2,3] and k = 2 return [1,2]
 *                  Note:
 *                       1.You may assume K is always valid, 1 <=k <= number of unique elements.
 *                       2.You algorithm's time complexity MUST BE better than O(n log n), where n is the array's size.
 *
 *        Version:  1.0
 *        Created:  10/27/2017 04:10:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <map>

void show(const std::vector<int> &ivec) {
	for (auto c : ivec) {
		std::cout << c << "   ";
	}
	std::cout << '\n';
}

/*
 * Method1: the program runs not fast.
 * Use associative container to solve the problem.
 * Note that: 
 *           1. elements in map and multimap are ordered.
 *           2. the keys of elements in map are unique while not in multimap.
 *           3. operator[] of map is different from others.
 *           4. operator[] is not supported in multiset.
 */
template<typename Container>
void show_map(const Container &C) {
	for (auto it = C.cbegin(); it != C.cend(); ++it) {
		std::cout << "first: " << it->first << "   second: " << it->second << std::endl;
	}
	std::cout << '\n';
}

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
	/*
	 * key = number
	 * mapped_value = occurrence
	 */
	std::map<int, int> imap;
	for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
		++ imap[*it];
	}

	/*
	 * key = occurrence
	 * mapped_value = number
	 */
	std::multimap<int, int> rimap;
	for (auto it = imap.cbegin(); it != imap.cend(); ++it) {
		rimap.insert({it->second, it->first});
	}

	/*
	 * use reverse iterator of multimap 
	 * you can also choose to use std::greater rather than std::less while defining rimap, and then you should use iterator rather reverse iterator
	 */
	std::vector<int> ret;
	for (auto it = rimap.crbegin(); k > 0 && it != rimap.crend(); ++it, --k) {
		ret.push_back(it->second);
	}
	return ret;
}

int main()
{
	std::vector<int> ivec0 {1, 1, 1, 2, 2, 3};
	show(topKFrequent(ivec0, 2));

	std::vector<int> ivec1 {-1, -1};
	show(topKFrequent(ivec1, 1));

	std::vector<int> ivec2 {1, 2};
	show(topKFrequent(ivec2, 2));

	std::vector<int> ivec3 {1, 3, 3, 5, 7, 7, 9, 3, 5, 7, 7};
	show(topKFrequent(ivec3, 3));
}
