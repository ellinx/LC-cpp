//
//  main.cpp
//  CodeTest
//
//  Created by LXU on 4/26/16.
//
//

#include "Solutions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Solutions dummy;
    
    /*int num = 2;
    
    vector<int> test = dummy.countBits(num);
    for (int i=0; i<num; i++) {
        cout <<  to_string(test[i]) + " ";
    }
    cout << endl;*/
    
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(9);
    dummy.moveZeroes(nums);
    return 0;
}
