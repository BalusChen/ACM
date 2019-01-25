/*
 * =====================================================================================
 *
 *       Filename:  reverse_string.cc
 *
 *    Description:  Write a function that takes a string as input and return
 *                  the string reversed
 *                  Example:
 *                      Given s = "hello", return "olleh"
 *
 *        Version:  1.0
 *        Created:  09/19/2017 06:29:32 PM
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

std::string ReverseString(std::string s){
	// in case that s is an empty string
	if(s.size() == 0){
		return s;
	}
	std::size_t i = 0, j = s.size() -1;
	while(i < j){
		std::swap(s[i++], s[j--]);
	}
	return s;
}

int main()
{
	std::string s1 { "function" };
	std::string s2 { "" };
	std::cout << s2.size() -1 << std::endl;
	std::cout << ReverseString(s1) << std::endl;
	std::cout << ReverseString(s2) << std::endl;
}
