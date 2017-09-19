/*
 * =====================================================================================
 *
 *       Filename:  judge_route_circle.cpp
 *
 *    Description:  Initially, there is a Robot at position(0,0).
 *                  Given a sequence of its moves, judge if this robort makes a circle
 *                  which means it moves back to the original place.
 *                  The move sequence is represented by a string.
 *                  And each move is represented by a character. The valid robot moves
 *                  are R(right), L(left), U(up), and D(down).
 *                  The output should be true or false representing whether the robot
 *                  makes a circle.
 *
 *        Version:  1.0
 *        Created:  09/17/2017 09:11:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#
#include <iostream>
#include <string>
#include <map>

/*  my answer... so foolish  */
bool JudgeCircle(std::string moves){
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

bool JudgeCircle2(std::string moves){
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
	std::cout << (JudgeCircle(moves1) ? "true: is circle" : "false: not circle") << std::endl;
	std::cout << (JudgeCircle2(moves2) ? "true: is circle" : "false: not circle") << std::endl;
}
