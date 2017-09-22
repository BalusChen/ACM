/*
 * =====================================================================================
 *
 *       Filename:  set_mismatch.cc
 *
 *    Description:  The set S originally contains numbers from 1 to n. But unfortunately,
 *                  due to the data error, one of the numbers in the set got duplicated
 *                  to another number in the set, which results in repetition of one
 *                  number and loss of another number.
 *                  
 *                  Given an array nums representing the data status of this set after
 *                  the error. You task is to firstly find the number occurs twice and
 *                  then find the number that is missing. Return them in the form of an
 *                  array.
 *
 *        Version:  1.0
 *        Created:  09/20/2017 02:53:14 PM
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
#include <algorithm>
#include <numeric>

/*
 *    Since these numbers are from 1 to n, and only one gets duplicated resulting in the
 *    loss of another number. 
 *    We can map every number to an array as the index of the array.
 *    That's to say, 2 = array[1], 7 = array[6]  ==> array[i] = array[array[i] - 1]
 *    At end, the duplicated number will be moved to the position where the lost number
 *    should have been.
 */
void PrintVector(const std::vector<int> &ivec);
std::vector<int> FindErrorNums(std::vector<int> &nums){
	for(int i = 0; i < nums.size(); ++i){
		while(nums[i] != nums[nums[i] - 1]) std::swap (nums[i], nums[nums[i]-1]);
	}
	for(int i = 0; i < nums.size(); ++i){
		if(nums[i] != i+1) return {nums[i], i+1};
	}
}

void PrintVector(const std::vector<int> &ivec){
	for(auto c : ivec){
		std::cout << c << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> ivec1 {2,2};
	std::vector<int> ivec2 {1,2,2,4};
	std::vector<int> ivec3 {2,3,2};
	std::vector<int> ivec4 {1,2,2,3,4,5,6,8};
	PrintVector(FindErrorNums(ivec1));
	PrintVector(FindErrorNums(ivec2));
	PrintVector(FindErrorNums(ivec3));
	PrintVector(FindErrorNums(ivec4));
}
