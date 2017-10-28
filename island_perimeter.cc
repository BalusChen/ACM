/*
 * =====================================================================================
 *
 *       Filename:  island_perimeter.cc
 *
 *    Description:  You are given a map form of a two-dimensional integer grid where
 *                  1 represents land and 0 represents water. Grid cells are connected
 *                  horizontally/vertically(not diagonally). The grid is completed
 *                  surrounded by water, and there is exactly one island(i.e., one or
 *                  more connected land cells). The island doesn't "lakes"(water inside
 *                  that isn't connected to the water around the island). One cell is a
 *                  square with side length 1. The grid is rectangular, width and height
 *                  don't exceed 100. Determine the perimeter of the island.
 *                  
 *                  Example:
 *                          Input:
 *	                           [[0,1,0,0]
 *	                            [1,1,1,0]
 *	                            [0,1,0,0]
 *	                            [1,1,0,0]]
 *                           Answer:16
 *                           
 *                           Explanation:
 *                                      *********************
 *                                      *    *  i *    *    *
 *                                      *********************
 *                                      *  i *  i *  i *    *
 *                                      *********************
 *                                      *    *  i *    *    *
 *                                      *********************
 *                                      * i  *  i *    *    *
 *                                      *********************
 *
 *
 *        Version:  1.0
 *        Created:  09/23/2017 05:36:03 PM
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

/*
 * My solution:
 * Fistly, expand th grid to a bigger grid, and thus we can avoid the consideration 
 *         of being the edge.
 * Secondly,for each grid cell, tring to scan if there is some other grid cell surrounding has
 */

int IslandPerimeter(std::vector<std::vector<int>> &grid){
	int sum = 0;
	std::vector<std::vector<int>> bigger_grid(grid.size() + 2, std::vector<int>(grid[0].size() + 2, 0));
	for(int i = 0; i < grid.size(); ++i){
		for(int j = 0; j < grid[0].size(); ++j){
			if(grid[i][j] == 1){
				bigger_grid[i+1][j+1] = 1;
				sum += 4;
			}
		}
	}
	for(int i = 0; i < bigger_grid.size(); ++i){
		for(int j = 0; j < bigger_grid[0].size(); ++j){
			if(bigger_grid[i][j] == 1){
				if(bigger_grid[i][j-1] == 1) -- sum;
				if(bigger_grid[i-1][j] == 1) -- sum;
				if(bigger_grid[i][j+1] == 1) -- sum;
				if(bigger_grid[i+1][j] == 1) -- sum;
			}
		}
	}
	return sum;
}
/*
 * A good solution some other coder wrote.
 * Two steps:
 *          1. find how many 1 in the map. If without the consideration of surrounding cells,
 *             the total perimeter should be the total amount of 1 times 4;.
 *          2. find how many cells walls that connect with both lands. We need to deduct twice
 *             of those lines from total perimeter.
 */
int IslandPerimeter2(std::vector<std::vector<int>> &grid){
	int count = 0, repeat = 0;
	for(int i = 0; i < grid.size(); ++i){
		for(int j = 0; j <grid[i].size(); ++j){
			if(grid[i][j] == 1){
				++ count;
				if(i != 0 && grid[i-1][j] == 1) ++ repeat;
				if(j != 0 && grid[i][j-1] == 1) ++ repeat;
			}
		}
	}
	return 4 * count - 2 * repeat;
}

int main()
{
	std::vector<std::vector<int>> grid {
		{ 0, 1, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 }
	};
	std::vector<std::vector<int>> ivec1 { {0}, {1} };
	std::vector<std::vector<int>> ivec2 { {1}, {0},{0} };
	std::vector<std::vector<int>> ivec3 { {1,1}, {1,0} };
	std::cout << IslandPerimeter(grid) << std::endl;
	std::cout << IslandPerimeter(ivec1) << std::endl;
	std::cout << IslandPerimeter(ivec2) << std::endl;
	std::cout << IslandPerimeter(ivec3) << std::endl;
	std::cout << IslandPerimeter2(grid) << std::endl;
	std::cout << IslandPerimeter2(ivec1) << std::endl;
	std::cout << IslandPerimeter2(ivec2) << std::endl;
	std::cout << IslandPerimeter2(ivec3) << std::endl;
}
