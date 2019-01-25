/*
 * =====================================================================================
 *
 *       Filename:  sort_characters_by_frequence.cc
 *
 *    Description:  Given a string, sort it in decreasing order base on the frequence of characters.
 *                  Example:
 *                          Input: "tree"
 *                          Output: "eert" ("eetr" is also valid)
 *
 *        Version:  1.0
 *        Created:  10/27/2017 08:48:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
#include <utility>//std::pair
#include <string>
#include <queue>//std::priority_queue
#include <map>

// function for debugging
template<typename Container>
void show(Container C) {
	for(auto it = C.cbegin(); it != C.cend(); ++it) {
		std::cout << "first: " << it->first << "  second: " << it->second << std::endl;
	}
	std::cout << '\n';
}

std::string frequencySort(std::string s) {
	std::map<char, int> cimap;
	for (auto c : s) {
		++ cimap[c];
	}

	std::priority_queue<std::pair<int, char>> pq;
	for (auto it = cimap.cbegin(); it != cimap.cend(); ++it) {
		pq.push({it->second, it->first});
	}

	std::string ret;
	while (!pq.empty()) {
		ret += std::string(pq.top().first, pq.top().second);
		pq.pop();
	}
	
	return ret;
}

int main()
{
	std::string str0 = "tree";
	std::cout << frequencySort(str0) << std::endl;

	std::string str1 = "cccaaa";
	std::cout << frequencySort(str1) << std::endl;
	
	std::string str2 = "Aabb";
	std::cout << frequencySort(str2) << std::endl;

	std::string str3 = "every day";
	std::cout << frequencySort(str3) << std::endl;

	std::string str4 = "colorful";
	std::cout << frequencySort(str4) << std::endl;
}
