#include "../Solutions.hpp"

using namespace std;

/***************** Evaluate Division *****************/
/*
 Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
 
 Example:
 Given a / b = 2.0, b / c = 3.0.
 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 return [6.0, 0.5, -1.0, 1.0, -1.0 ].
 
 The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
 
 According to the example above:
 
 equations = [ ["a", "b"], ["b", "c"] ],
 values = [2.0, 3.0],
 queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
 The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

void BFS(queue<pair<string,double>>& toVisit, string target, double& val,unordered_map<string,vector<pair<string,double>>>& mp,unordered_set<string>& toNodes);

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map<string,vector<pair<string,double>>> mp;
    unordered_set<string> toNodes;
    vector<double> res;
    
    for (int i=0;i<equations.size();i++) {
        string a = equations[i].first;
        string b = equations[i].second;
        toNodes.insert(a);
        toNodes.insert(b);
        //add a->b
        auto iter = mp.find(a);
        if (iter!=mp.end()) {
            iter->second.push_back(pair<string,double>(b,values[i]));
        } else {
            vector<pair<string,double>> tmp;
            tmp.push_back(pair<string,double>(a,1.0));
            tmp.push_back(pair<string,double>(b,values[i]));
            mp[a] = tmp;
        }
        //add b->a
        iter = mp.find(b);
        if (iter!=mp.end()) {
            iter->second.push_back(pair<string,double>(a,1/values[i]));
        } else {
            vector<pair<string,double>> tmp;
            tmp.push_back(pair<string,double>(b,1.0));
            tmp.push_back(pair<string,double>(a,1/values[i]));
            mp[b] = tmp;
        }
    }
    
    for (int i=0;i<queries.size();i++) {
        string a = queries[i].first;
        string b = queries[i].second;
        unordered_set<string> dupToNode(toNodes);
        auto iter = mp.find(a);
        if (iter!=mp.end()) {
            double val = -1.0;
            queue<pair<string,double>> toVisit;
            for (int k=0;k<iter->second.size();k++) {
                if (dupToNode.find(iter->second[k].first)!=dupToNode.end()) {
                    toVisit.push(iter->second[k]);
                }
            }
            dupToNode.erase(a);
            BFS(toVisit,b,val,mp,dupToNode);
            res.push_back(val);
        } else {
            res.push_back(-1.0);
        }
    }
    return res;
}

void BFS(queue<pair<string,double>>& toVisit, string target, double& val,unordered_map<string,vector<pair<string,double>>>& mp,unordered_set<string>& toNodes) {

    while(!toVisit.empty()) {
        if (toVisit.front().first==target) {
            val = toVisit.front().second;
            return;
        } else {
            auto iter = mp.find(toVisit.front().first);
            if (iter!=mp.end()) {
                for (int i=0;i<iter->second.size();i++) {
                    if (toNodes.find(iter->second[i].first)!=toNodes.end()) {
                        toVisit.push(pair<string,double>(iter->second[i].first,(toVisit.front().second)*(iter->second[i].second)));
                    }
                }
                toNodes.erase(toVisit.front().first);
            }
        }
        toVisit.pop();
    }
}
