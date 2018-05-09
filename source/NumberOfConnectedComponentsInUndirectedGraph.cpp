#include "../Solutions.hpp"
using namespace std;

/*************** Number of Connected Components in an Undirected Graph **************/
/*
 Given n nodes labeled from 0 to n – 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
 
 Example 1:
 
 0          3
 
 |          |
 
 1 — 2      4
 
 Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 
 Example 2:
 
 0       4
 
 |       |
 
 1 — 2 — 3
 
 Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 
 Note:
 
 You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */
int getRoot(int node, vector<int>& roots);

int Solutions::countComponents(int n, vector<pair<int,int>>& edges) {
    vector<int> roots(n,0);
    int count = n;
    iota(roots.begin(),roots.end(),0);
    
    for (auto edge : edges) {
        int rootU = getRoot(edge.first, roots);
        int rootV = getRoot(edge.second, roots);
        if (rootU!=rootV) {
            roots[rootU] = rootV;
            count--;
        }
    }
    return count;
}

int getRoot(int node, vector<int>& roots) {
    while (node!=roots[node]) {
        node = roots[node];
    }
    return roots[node];
}
