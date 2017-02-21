#include "Solutions.hpp"

using namespace std;

void printVector(vector<int>& vec);
void printVector(vector<string>& vec);
vector<int> InitVectorInt(int* array, int n);
vector<string> InitVectorString(string* array, int n);

int main() {
    Solutions dummy;
    vector<int> vec_int;
    vector<string> vec_string;

    int nums[] = {1,2,3,4,5,6,7};
    
    string words[] = {"leet","code","cog"};
    
    int input_type = INPUT_VEC_STR;
    
    switch(input_type) {
        case INPUT_VEC_INT:
            vec_int = InitVectorInt(nums, 7);
            break;
        case INPUT_VEC_STR:
            vec_string = InitVectorString(words, 3);
            break;
        default:
            cout<<"Wrong input type, initialization fails!"<<endl;
            break;
    }
    

    bool result = dummy.wordBreak("leetcode",vec_string);
	cout<<"result is:"<<endl;
    //printVector(result);
	cout<<result<<endl;
    return 0;
}


//Initialization functions
vector<int> InitVectorInt(int* array, int n) {
    vector<int> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }
    printVector(res);
    return res;
}

vector<string> InitVectorString(string* array, int n) {
    vector<string> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }
    printVector(res);
    return res;
}

//print functions
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
void printVector(vector<string>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}
