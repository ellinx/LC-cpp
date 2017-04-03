#include "Solutions.hpp"

using namespace std;

void printVector(vector<int>& vec);
void printVector(vector<string>& vec);
vector<int> InitVectorInt(int* array, int n);
vector<string> InitVectorString(string* array, int n);
vector<Interval> InitVectorInterval(Interval* array, int n);
ListNode* InitListInt(int* array, int n);
void printListInt(ListNode* head);

int main() {
    Solutions dummy;
    vector<int> vec_int;
    vector<string> vec_string;
    vector<Interval> vec_interval;
	ListNode* list_int = NULL;
	ListNode* list_int2 = NULL;

    int nums[] = {7, 2, 4, 3};
	int nums2[] = {5, 6, 4};
    
    string words[] = {"leet","code","cog"};
    
    Interval intervals[] = {Interval(0,70),Interval(5,40),Interval(20,50),Interval(50,60)};
    
    int input_type = INPUT_LIST_INT;
    
    switch(input_type) {
        case INPUT_VEC_INT:
            cout<<"Input: ";
            vec_int = InitVectorInt(nums, 4);
            break;
        case INPUT_VEC_STR:
            cout<<"Input: ";
            vec_string = InitVectorString(words, 3);
            break;
        case INPUT_VEC_INTERVALS:
            cout<<"Input: ";
            vec_interval = InitVectorInterval(intervals, 4);
            break;
		case INPUT_LIST_INT:
			cout<<"Input:"<<endl;
            list_int = InitListInt(nums, 4);
			list_int2 = InitListInt(nums2, 3);
			break;
        default:
            break;
    }
    

	ListNode* result = dummy.addTwoNumbersII(list_int, list_int2);
	cout<<"result is:"<<endl;


    //printVector(result);
	//cout<<result<<endl;
	printListInt(result);
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

ListNode* InitListInt(int* array, int n) {
	
	ListNode* head = new ListNode(array[0]);
	ListNode* cur = head;

	for (int i=1;i<n;i++) {
		cur->next = new ListNode(array[i]);
		cur = cur->next;
	}
	printListInt(head);
	return head;
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

void printListInt(ListNode* head) {
	cout<<"[";
	while (head != NULL) {
		cout<<head->val;
		head = head->next;
		if (head != NULL) {
			cout<<"->";
		}
	}
	cout<<"]"<<endl;
}
