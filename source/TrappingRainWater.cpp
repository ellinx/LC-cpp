#include "../Solutions.hpp"

/***************** Trapping Rain Water *****************/
/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

4|
3|                     __
2|         __         |  |__    __
1|   __   |  |__    __|     |__|  |__
0|__|__|__|__ __|__|__ __ __ __ __ __|
  0  1  0  2  1  0  1  3  2  1  2  1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

int Solutions::trap(vector<int>& height) {
	if (height.size()<3) return 0;
	//pre-process the left height and right height of one unit
	//computer unit by unit


	//left and right max height include itself
	vector<int> left(height.size(), height.front());
	vector<int> right(height.size(), height.back());

	for (int i=1;i<height.size();i++) {
		left[i] = max(left[i-1], height[i]);
	}

	for (int i=height.size()-2;i>=0;i--) {
		right[i] = max(right[i+1], height[i]);
	}

	int res = 0;
	for (int i=0;i<height.size();i++) {
		res += min(left[i], right[i]) - height[i];
	}
	return res;
}


/*********** Trapping Rain Water II **************/
/*
 Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
 
 Note:
 Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
 
 Example:
 
 Given the following 3x6 height map:
 [
 [1,4,3,1,3,2],
 [3,2,1,3,2,4],
 [2,3,3,2,3,1]
 ]
 
 Return 4.
 */

int Solutions::trapRainWaterII(vector<vector<int>>& heightMap) {
    return 0;
}
