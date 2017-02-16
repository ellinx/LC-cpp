

#include "Solutions.hpp"

using namespace std;
void printVector(vector<int>& vec);

int main() {
    Solutions dummy;  
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
	nums.push_back(-4);
    printVector(nums);

	vector<string> words;
	words.push_back("hot");
	words.push_back("dot");
	words.push_back("dog");
	words.push_back("lot");
	words.push_back("log");
	words.push_back("cog");

    vector<vector<int>> result = dummy.threeSum(nums);
	
	cout<<"result is:"<<endl;
	cout<<"["<<endl;
	for (int i=0;i<result.size();i++) {
		printVector(result[i]);
	}
	cout<<"]";
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
