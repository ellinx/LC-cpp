#include "../Solutions.hpp"
using namespace std;

/*************** Reconstruct Itinerary **************/
/*
 Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
 
 Note:
 If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 All airports are represented by three capital letters (IATA code).
 You may assume all tickets form at least one valid itinerary.
 Example 1:
 tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 Example 2:
 tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 */

//Use Hierholzer’s Algorithm to find Eulerian path
vector<string> Solutions::findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> edges;
    stack<string> current_path;
    vector<string> path;
    
    for (auto ticket : tickets) {
        if (edges.find(ticket.first) == edges.end()) {
            //new
            edges.emplace(ticket.first,multiset<string>());
            edges[ticket.first].insert(ticket.second);
        } else {
            edges[ticket.first].insert(ticket.second);
        }
    }
    
    current_path.push("JFK");
    while (!current_path.empty()) {
        string current_airport = current_path.top();
        if (!edges[current_airport].empty()) {
            //there is unused edge
            string new_airport = *edges[current_airport].begin();
            edges[current_airport].erase(edges[current_airport].begin());
            current_path.push(new_airport);
        } else {
            //there is no unused edge
            path.push_back(current_airport);
            current_path.pop();
        }
    }
    
    reverse(path.begin(), path.end());
    return path;
}

