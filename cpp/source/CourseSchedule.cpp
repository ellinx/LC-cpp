#include "../Solutions.hpp"

using namespace std;

/***************** Course Schedule  *****************/
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
*/
bool Solutions::canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> indegree(numCourses,0);
	unordered_set<int> vertex;
	unordered_set<int> edgeNode;
	unordered_map<int,vector<int>> fromTo;
	for (int i=0;i<prerequisites.size();i++) {
		indegree[prerequisites[i].first]++;
		edgeNode.insert(prerequisites[i].first);
		edgeNode.insert(prerequisites[i].second);
		if (fromTo.find(prerequisites[i].second)==fromTo.end()) {
			vector<int> toVertex;
			toVertex.push_back(prerequisites[i].first);
			fromTo[prerequisites[i].second] = toVertex;
		} else {
			vector<int> toVertex = fromTo[prerequisites[i].second];
			toVertex.push_back(prerequisites[i].first);
			fromTo[prerequisites[i].second] = toVertex;
		}
	}

	for (auto iter=edgeNode.begin();iter!=edgeNode.end();iter++) {
		if (indegree[*iter]==0) {
			vertex.insert(*iter);
		}
	}

	while (!vertex.empty()) {
		auto iter = vertex.begin();
		int curNode = *iter;
		vertex.erase(iter);
		if (fromTo.find(curNode)!=fromTo.end()) {
			vector<int> toVertex = fromTo[curNode];
			for (int i=0;i<toVertex.size();i++) {
				indegree[toVertex[i]]--;
				if (indegree[toVertex[i]]==0) {
					vertex.insert(toVertex[i]);
				}
			}
			fromTo.erase(curNode);
		}
	}

	if (fromTo.empty()) return true;
	return false;
}