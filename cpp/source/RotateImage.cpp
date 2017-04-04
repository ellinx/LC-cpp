#include "../Solutions.hpp"

using namespace std;

/***************** Rotate Image *****************/
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

void Solutions::rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();

	if (n<2) return;

	for (int i=0;i<=(n-1)/2;i++) {
		int offset = 0;
		while (offset<n-1-2*i) {
			int tmp = matrix[i][i+offset];
			matrix[i][i+offset] = matrix[n-1-i-offset][i];
			matrix[n-1-i-offset][i] = matrix[n-1-i][n-1-i-offset];
			matrix[n-1-i][n-1-i-offset] = matrix[i+offset][n-1-i];
			matrix[i+offset][n-1-i] = tmp;
			offset++;
		}
	}
}