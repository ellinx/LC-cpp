#include "../Solutions.hpp"

using namespace std;

/***************** Insert Delete GetRandom O(1) - Duplicates allowed *****************/
/*
Design a data structure that supports all following operations in average O(1) time.
Note: Duplicate elements are allowed.

    insert(val): Inserts an item val to the collection.
    remove(val): Removes an item val from the collection if present.
    getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.

Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
*/

class RandomizedCollection {
	unordered_map<int,vector<int>> dataMap;
	vector<int> data;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
		dataMap.clear();
		data.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
		data.push_back(val);
		auto iter = dataMap.find(val);
		if (iter==dataMap.end()) {
			vector<int> tmp(1,data.size()-1);
			dataMap.emplace(val,tmp);
			return true;
		} else {
			iter->second.push_back(data.size()-1);
			return false;
		}
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = dataMap.find(val);
		if (iter==dataMap.end()) {
			return false;
		} else {
			int index = iter->second.back();
			data[index] = data.back();
			vector<int>& tmp = dataMap.find(data.back())->second;
			for (int i=tmp.size()-1;i>=0;i--) {
				if (tmp[i] == data.size()-1) {
					tmp[i] = index;
					break;
				}
			}
			data.pop_back();
			iter->second.pop_back();
			if (iter->second.empty()) dataMap.erase(val);
			return true;
		}
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand()%(data.size());
		return data[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */