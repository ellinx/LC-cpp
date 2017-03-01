#include "Solutions.hpp"

using namespace std;

void printVector(vector<int>& vec);
void printVector(vector<string>& vec);
vector<int> InitVectorInt(int* array, int n);
vector<string> InitVectorString(string* array, int n);
vector<Interval> InitVectorInterval(Interval* array, int n);

int main() {
    Solutions dummy;
    vector<int> vec_int;
    vector<string> vec_string;
    vector<Interval> vec_interval;

    int nums[] = {1,1,5};
    
    string words[] = {"leet","code","cog"};
    
    Interval intervals[] = {Interval(0,70),Interval(5,40),Interval(20,50),Interval(50,60)};
    
    int input_type = INPUT_VEC_INTERVALS;
    
    switch(input_type) {
        case INPUT_VEC_INT:
            cout<<"Input:";
            vec_int = InitVectorInt(nums, 3);
            break;
        case INPUT_VEC_STR:
            cout<<"Input:";
            vec_string = InitVectorString(words, 3);
            break;
        case INPUT_VEC_INTERVALS:
            cout<<"Input:";
            vec_interval = InitVectorInterval(intervals, 4);
            break;
        default:
            break;
    }
    

    int result = dummy.minMeetingRooms(vec_interval);
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

vector<Interval> InitVectorInterval(Interval* array, int n) {
    vector<Interval> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }
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
