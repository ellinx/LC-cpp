#include "../Solutions.hpp"

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


/***************** Course ScheduleII  *****************/
/*
 There are a total of n courses you have to take, labeled from 0 to n - 1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 
 There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 
 For example:
 
 2, [[1,0]]
 
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 
 4, [[1,0],[2,0],[3,1],[3,2]]
 
 There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 */

vector<int> Solutions::findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> res;
    vector<int> indegree(numCourses,0);
    unordered_set<int> toVisit;
    unordered_set<int> vertex;
    unordered_map<int,vector<int>> fromTo;
    
    for (int i=0;i<prerequisites.size();i++) {
        indegree[prerequisites[i].first]++;
        vertex.insert(prerequisites[i].first);
        vertex.insert(prerequisites[i].second);
        if (fromTo.find(prerequisites[i].second)==fromTo.end()) {
            vector<int> toNode;
            toNode.push_back(prerequisites[i].first);
            fromTo[prerequisites[i].second] = toNode;
        } else {
            vector<int> toNode = fromTo[prerequisites[i].second];
            toNode.push_back(prerequisites[i].first);
            fromTo[prerequisites[i].second] = toNode;
        }
    }
    
    for (int i=0;i<numCourses;i++) {
        if (indegree[i]==0) {
            if (vertex.find(i)==vertex.end()) {
                res.push_back(i);
            } else {
                toVisit.insert(i);
            }
        }
    }
    
    while(!toVisit.empty()) {
        auto iter = toVisit.begin();
        int curNode = *iter;
        res.push_back(curNode);
        toVisit.erase(*iter);
        if (fromTo.find(curNode)!=fromTo.end()) {
            vector<int> toNode = fromTo[curNode];
            for (int i=0;i<toNode.size();i++) {
                indegree[toNode[i]]--;
                if (indegree[toNode[i]]==0) {
                    toVisit.insert(toNode[i]);
                }
            }
            fromTo.erase(curNode);
        }
    }
    
    if (fromTo.empty()) return res;
    
    return vector<int>();
}
