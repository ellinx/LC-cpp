
/***************** Rectangle Area *****************/
/*
 Find the total area covered by two rectilinear rectangles in a 2D plane.
 
 Each rectangle is defined by its bottom left corner and top right corner.
 Assume that the total area is never beyond the maximum possible value of int.
 */

#include "../Solutions.hpp"

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = (C-A)*(D-B);
    int area2 = (G-E)*(H-F);
    
    int left = max(A,E);
    int right = min(C,G);
    int top = min(D,H);
    int bottom = max(B,F);
    
    if (right>left && top>bottom) {
        return area1+area2-(top-bottom)*(right-left);
    }
    return area1+area2;
}
