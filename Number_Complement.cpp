/*
 * =====================================================================================
 *
 *       Filename:  Number_Complement.cpp
 *
 *    Description:  Given a positive integer, output its complement number.
 *                  The complement strategy is to flip the bits of its binary
 *                  representation.
 *                  Note:
 *                      1.The given integer if guaranteed to fit within the range
 *                        of a 32-bit signed integer.
 *                      2.You should assume no leading zero bit in the integer's 
 *                        binary representation.
 *
 *        Version:  1.0
 *        Created:  09/18/2017 03:44:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
constexpr int pow(int base, int expr){
	return (expr == 0) ?  1 : base * pow(base, expr-1); 
}

int find_complement(int num){
	int i = 0;
	int ret = 0;
	while(num != 0){
		if(num % 2 == 0){
			ret += pow(2,i);
		}
		num = num >> 1;
		++i;

	}
	return ret;
}

int main()
{
	std::cout << find_complement(7) << std::endl;
	std::cout << find_complement(161) << std::endl;
	std::cout << pow(2,3) << std::endl;
	std::cout << pow(3,4) << std::endl;

}
