/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_two_arrays.cc
 *
 *    Description:  Given two arrays, write a function to compute their intersection.
 *                  Example:
 *                          Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]
 *                  Note:
 *                       1.Each element in the result must be unique.
 *                       2.The result can be in any order.
 *
 *        Version:  1.0
 *        Created:  09/24/2017 03:26:06 PM
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
#include <unordered_map>
#include <algorithm>

void PrintVector(const std::vector<int> &ivec){
	for(auto c : ivec){
		std::cout << c << "  ";
	}
	std::cout << '\n';
}
// my solution:
std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
	std::vector<int> ret;
	std::unordered_map<int, int> nums1_map;
	for(auto c : nums1){
		++ nums1_map[c];
	}
	for(auto c : nums2){
		if(nums1_map.count(c) != 0){
			if(find(ret.begin(), ret.end(), c) == ret.end()){
				ret.push_back(c);
			}
		}
	}
	return ret;
}

int main()
{
	std::vector<int> ivec1 {1, 2, 2, 1};
	std::vector<int> ivec2 {2, 2};
	PrintVector(intersection(ivec1, ivec2));
	std::vector<int> ivec3 {1,3,5,7};
	std::vector<int> ivec4 {3,7,11};
	PrintVector(intersection(ivec3, ivec4));
	std::vector<int> ivec5;
	std::vector<int> ivec6;
	PrintVector(intersection(ivec5, ivec6));
}
