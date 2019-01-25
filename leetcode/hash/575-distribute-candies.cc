/*
 * =====================================================================================
 *
 *       Filename:  distribute_cadies.cc
 *
 *    Description:  Given an integer array with even length, where different numbers in
 *                  this array represent kinds of candies. Each number meansone candy
 *                  of the corresponding kind. You need to distribute these candies
 *                  equally in number to brother and sister. Return the maximum number
 *                  of kinds of candies the sister could gain.
 *
 *        Version:  1.0
 *        Created:  09/20/2017 02:32:22 PM
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

int DistributeCandies(std::vector<int> &candies){
	std::unordered_map<int,int> candy_kinds;
	//count the kind of candies;
	for(auto c : candies){
		++ candy_kinds[c];
	}
	if(candy_kinds.size() >= candies.size()/2){
		return candies.size()/2;
	}else{
		return candy_kinds.size();
	}
}

int main()
{
	std::vector<int> candies1 {1,1,2,2,3,3};
	std::vector<int> candies2 {1,1,2,3};
	std::vector<int> candies3 {1,2,3,4,5,6,7,8};
	std::cout << DistributeCandies(candies1) << std::endl;
	std::cout << DistributeCandies(candies2) << std::endl;
	std::cout << DistributeCandies(candies3) << std::endl;
}
