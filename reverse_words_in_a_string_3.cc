/*
 * =====================================================================================
 *
 *       Filename:  reverse_words_in_a_string_3.cc
 *
 *    Description:  Given a string, you need to reverse the order of character in each
 *                  word within a sentence while still preserving whitespace and initial
 *                  word order.
 *
 *        Version:  1.0
 *        Created:  09/19/2017 06:08:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void ReverseAWord(std::string &s){
	std::size_t i = 0, j = s.size() -1;
	while(i < j){
		std::swap(s[i++], s[j--]);
	}
}

/*  My own solution. The program runs very slowly. */
std::string ReverseWords(std::string s){
	std::vector<std::string> str_vec;
	std::string ret;
	std::istringstream line(s); //cut the string into several words
	std::string word;
	while(line >> word){
		str_vec.push_back(word);
	}
	for(auto &str : str_vec){
		ReverseAWord(str); //reverse each word
	}
	for(std::size_t i = 0; i < str_vec.size(); ++i){
		if(i == str_vec.size() - 1){
			ret += str_vec[i];
		}else{
			ret = ret + str_vec[i] + " "; //concatenate these words into a string
		}
	}
	return ret;
}

int main()
{
	std::string s1 {"Let's take LeetCode contest"};
	std::cout << ReverseWords(s1) << std::endl;
	std::cout << "original length: " << s1.size() << "  reversed length: " << ReverseWords(s1).size() << std::endl;
}
