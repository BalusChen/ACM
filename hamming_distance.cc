/*
 * =====================================================================================
 *
 *       filename:  hamming_distance.cc
 *
 *    Description:  The Hamming distance between two integers is the numbers of positions at which the coresponding
 *                  bits are diffent.
 *                  Given two integers x and y, calculate the Hamming distance.
 *        Version:  1.0
 *        Created:  09/17/2017 08:47:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>

int hamming_distance(int x, int y){
	int result = x ^ y;
	int num = 0;
	while(result != 0){
		if(result % 2){
			++ num;
		}
		result = result >> 1;
	}
	return num;
}

int main()
{
	int i = 7;
	std::cout << (7 >> 3) << std::endl;
	std::cout << (1 ^ 4 ) << std::endl;
	std::cout << hamming_distance(1,4) << std::endl;
	std::cout << hamming_distance(161,111) << std::endl;
	std::cout << hamming_distance(1,14) << std::endl;
}

