/*
 * =====================================================================================
 *
 *       Filename:  keyboard_row.cc
 *
 *    Description:  Given a List of words, return the words that can be typed
 *                  using letters of a alphabet on only one row's of American
 *                  keyboard like the image below(sorry, ther is no image here)
 *
 *        Version:  2.0
 *        Created:  09/19/2017 02:27:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
#include <cctype> // tolower
#include <vector>
#include <string>
#include <unordered_set>

/* 
 *   oh my God, my program runs so slowly!  
 *   Obviously, I should have used the associative container.
 *   It suits this situation very well.
 */

std::vector<std::string> FindWords(std::vector<std::string> &words){
	std::vector<std::string> ret;
	for(const auto &str : words){
		std::size_t char_in_row1 = 0;
		std::size_t char_in_row2 = 0;
		std::size_t char_in_row3 = 0;
		std::size_t num_is_not_zero  = 0;
		for(int i = 0; i < str.size(); ++i){
			switch(tolower(str[i])){
				case'q':
				case'w':
				case'e':
				case'r':
				case't':
				case'y':
				case'u':
				case'i':
				case'o':
				case'p':
					++ char_in_row1; break;
				case'a':
				case's':
				case'd':
				case'f':
				case'g':
				case'h':
				case'j':
				case'k':
				case'l':
					++ char_in_row2; break;
				case'z':
				case'x':
				case'c':
				case'v':
				case'b':
				case'n':
				case'm':
					++ char_in_row3; break;
			}
		}
		if(char_in_row1 != 0) ++ num_is_not_zero;
		if(char_in_row2 != 0) ++ num_is_not_zero;
		if(char_in_row3 != 0) ++ num_is_not_zero;
		if(num_is_not_zero == 1){
			ret.push_back(str);
		}
	}
	return ret;
}

/*  good C++ solution other coders wrote  */
std::vector<std::string> FindWords2(std::vector<std::string> &words){
	std::unordered_set<char> row1 {'q','w','e','r','t','y','u','i','o','p'};
	std::unordered_set<char> row2 {'a','s','d','f','g','h','j','k','l'};
	std::unordered_set<char> row3 {'z','x','c','v','b','n','m'};
	std::vector<std::unordered_set<char>> rows{row1,row2,row3};
	std::vector<std::string> valid_words;

	for(int i = 0; i < words.size(); ++i){
		int row = 0;
		// find the row the first character of every string belongs to
		for(int k = 0; k < 3; ++k){
			if(rows[k].count(static_cast<char>(tolower(words[i][0]))) > 0) row = k;
		}

		// check if all the other characters are belongs to the same row as the first char does
		// use 'break' to save some time for unnecessary checks
		for(int j = 0; j < words[i].size(); ++j){
			if(rows[row].count(static_cast<char>(tolower(words[i][j]))) == 0) break;
			if(j == words[i].size() - 1) valid_words.push_back(words[i]);
		}
	}
	return valid_words;
}

int main()
{
	std::vector<std::string> input{"fuck","qwer","fjgj","cnzmvc","delicious","mock"};
	auto output = FindWords(input);
	for(const auto &str : output){
		std::cout << str << std::endl;
	}
	auto output2 = FindWords2(input);
	for(const auto &str : output2){
		std::cout << str << std::endl;
	}
}
