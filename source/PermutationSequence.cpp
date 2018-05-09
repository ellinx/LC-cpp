
/***************** Permutation Sequence *****************/
/*
 The set [1,2,3,…,n] contains a total of n! unique permutations.
 
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 
 Note: Given n will be between 1 and 9 inclusive.
 */

#include "../Solutions.hpp"

void process(set<string>& numSet, string& res, int k);

string Solutions::getPermutation(int n, int k) {
    set<string> numSet;
    for (int i=0;i<n;i++) {
        numSet.insert(to_string(i+1));
    }
    
    string res;
    process(numSet, res, k);
    return res;
}

void process(set<string>& numSet, string& res, int k) {
    if (numSet.empty()) return;
    
    int n = numSet.size();
    int segNum = 1;
    for (int i=0;i<n-1;i++) {
        segNum *= i+1;
    }
    for (auto iter=numSet.begin();iter!=numSet.end();iter++) {
        if (k>segNum) {
            k -= segNum;
            continue;
        }
        
        string tmp = *iter;
        cout<<"tmp:"<<tmp<<endl;
        numSet.erase(iter);
        res += tmp;
        break;
    }
    process(numSet, res, k);
}
