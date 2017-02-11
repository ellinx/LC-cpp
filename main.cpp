

#include "Solutions.hpp"

using namespace std;
void printVector(vector<int>& vec);

int main() {
    Solutions dummy;  
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
	nums.push_back(3);
	printVector(nums);
    int result = dummy.minSubArrayLen(7, nums);
	cout<<"result is:"<<endl;
	cout<<result<<endl;
    return 0;
}


//
void printVector(vector<int>& vec) {
	cout<<"[";
	for (int i=0;i<vec.size();i++) {
		cout<<vec[i];
		if (i<vec.size()-1) {
			cout<<",";
		}
	}
	cout<<"]"<<endl;
}