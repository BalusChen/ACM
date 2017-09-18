/*
 * =====================================================================================
 *
 *       Filename:  Judge_Route_Circle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2017 09:11:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#
#include <iostream>
#include <string>
#include <map>

/*  my answer... so foolish  */
bool judge_circle(std::string moves){
	std::map<char, int> sumMoves;
	for(char ch : moves){
		switch(ch) {
			case 'R':
				++ sumMoves['R'];
				break;
			case 'L':
				++ sumMoves['L'];
				break;
			case 'U':
				++ sumMoves['U'];
				break;
			case 'D':
				++ sumMoves['D'];
				break;
		}
	}
	if(!((sumMoves['R'] == sumMoves['L']) && (sumMoves['U'] == sumMoves['D']))){
		return false;
	}
	return true;
}

bool judge_circle_2(std::string moves){
	int v = 0;
	int h = 0;
	for (char ch : moves){
		switch(ch){
			case 'U': ++v; break;
			case 'D': --v; break;
			case 'R': ++h; break;
			case 'L': --h; break;
		}
	}
	return v == 0 && h == 0;
}

int main()
{
	std::string moves1 = "LLRRDDUU";
	std::string moves2 = "LLRRDDUUD";
	std::cout << (judge_circle(moves1) ? "true: is circle" : "false: not circle") << std::endl;
	std::cout << (judge_circle_2(moves2) ? "true: is circle" : "false: not circle") << std::endl;
}
