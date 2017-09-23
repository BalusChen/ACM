/*
 * =====================================================================================
 *
 *       Filename:  minimum_index_of_two_lists.cc
 *
 *    Description:  Suppose Andy and Doris want to choose a restaurant for dinner, and
 *                  they both have a list of favourite resturants represented by strings
 *                  
 *                  You need to help them to find out their common interest with the 
 *                  least list index sum. If there is a choice tie between answers,
 *                  output all of them with no order requirement.You could assume
 *                  there always exists an answer.
 *
 *                  Note:
 *                       1.The length of both lists will be in the range of [1,1000].
 *                       2.The lenght of strings in both lists will be in the range of [1,30].
 *                       3.The index is starting from 0 the list length minux 1.
 *                       4.No duplicates in both lists.
 *
 *        Version:  1.0
 *        Created:  09/23/2017 03:51:04 PM
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
#include <string>
#include <utility> // pair
#include <unordered_map>

static const int KMaxIndex = 2000;

/* 
 * My own solution to the question.
 * Sadly, the program runs very slowly.
 */
std::vector<std::string> FindRestaurant(std::vector<std::string> list1, std::vector<std::string>  list2){
	std::vector<std::string> ret;
	std::pair<int, int> index{1000,1000};
	for(int i = 0; i < list1.size(); ++i){
		for(int j = 0; j < list2.size(); ++j){
			if(list1[i] == list2[j]){
				if(i + j == index.first + index.second){
					ret.push_back(list1[i]);
				}
				if(i + j < index.first + index.second){
					ret.clear();
					index.first = i;
					index.second = j;
					ret.push_back(list1[i]);
				}
			}
		}
	}
	return ret;
}

/*
 * Solution of some other coder in LeetCode.
 */
std::vector<std::string> FindRestaurant2(std::vector<std::string> list1, std::vector<std::string> list2){
	std::vector<std::string> ret;
	std::unordered_map<std::string, int> index;
	int min = KMaxIndex;
	for(int i = 0; i < list1.size(); ++i){
		index[list1[i]] = i;
	}
	for(int j = 0; j < list2.size(); ++j){
		if(index.count(list2[j]) != 0){
			if(index[list2[j]] + j < min){ //find a better option and then refresh the index sum ==>min 
				min = index[list2[j]] + j;
				ret.clear();
				ret.push_back(list2[j]);
			}else if(index[list2[j]] + j == min){ //in case that there are more than one option
				ret.push_back(list2[j]); 
			}
		}
	}
	return ret;
}

void PrintVector(const std::vector<std::string> &svec){
	for(auto &c : svec){
		std::cout << c << std::endl;
	}
}

int main()
{
	std::vector<std::string> svec1 { "Shogun", "Tapioca Express", "Burger King" "KFC" };
	std::vector<std::string> svec2 { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
	std::vector<std::string> svec3 { "Shougun", "Tapioca Express", "Burger King", "KFC" };
	std::vector<std::string> svec4 { "KFC", "Shougun", "Burger King" };
	PrintVector(FindRestaurant(svec1, svec2));
	PrintVector(FindRestaurant(svec3, svec4));
	PrintVector(FindRestaurant2(svec1, svec2));
	PrintVector(FindRestaurant2(svec3, svec4));
}
