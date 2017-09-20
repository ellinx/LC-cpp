#include "Solutions.hpp"
#include "main.h"
#include "Tester.hpp"


int main() {
    Solutions dummy;
    Tester tester;
    
    //inputs
    vector<int> vec_int = {1, 2, 3, 4, 5};
    vector<string> vec_string = {"oath","pea","eat","rain"};
    vector<Interval> vec_interval = {Interval(0,70),Interval(5,40),Interval(20,50),Interval(50,60)};
    vector<vector<int>> matrix_int = {
                            {12,13,1,12},
                            {13,4,13,12},
                            {13,8,10,12},
                            {12,13,12,12},
                            {13,13,13,13}
                        };
    vector<vector<char>> matrix_char = {
                            /*{'o', 'a', 'a', 'n'},
                            {'e', 't', 'a', 'e'},
                            {'i', 'h', 'k', 'r'},
                            {'i', 'f', 'l', 'v'}*/
                            {'A','B','C','E'},
                            {'S','F','C','S'},
                            {'A','D','E','E'}
                        };
    
	ListNode* list_int = tester.initListInt(vector<int>{1, 2, 3, 4, 5});
	ListNode* list_int2 = tester.initListInt(vector<int>{5, 6, 4});


    
    //******************* print inputs ******************************************************
    int input_type = INPUT_LIST_INT;
    
    switch(input_type) {
        case INPUT_VEC_INT:
            cout<<"Input: ";
            printVector(vec_int);
            break;
        case INPUT_VEC_STR:
            cout<<"Input: ";
            printVector(vec_string);
            break;
        case INPUT_VEC_INTERVALS:
            cout<<"Input: ";
            printVector(vec_interval);
            break;
		case INPUT_LIST_INT:
			cout<<"Input:"<<endl;
            printList(list_int);
            //printList(list_int2);
			break;
		case INPUT_MATRIX_INT:
			cout<<"Input:"<<endl;
            printMatrix(matrix_int);
			break;
        case INPUT_MATRIX_CHAR:
            cout<<"Input:"<<endl;
            printMatrix(matrix_char);
            break;
        default:
            break;
    }
    cout<<endl;
    //******************************************************************************************

    //test code
	string result = dummy.getPermutation(3,1);
	cout<<"result is:"<<endl;
	
	
	//printMatrix(matrix_int);
//    printVector(result);
	cout<<result<<endl;
    //printList(result);
    return 0;
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
void printVector(vector<bool>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}
void printVector(vector<char>& vec) {
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
void printVector(vector<pair<int,int>>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<"["<<vec[i].first<<","<<vec[i].second<<"]";
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}
void printVector(vector<Interval> & vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<"["<<vec[i].start<<","<<vec[i].end<<"]";
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void printList(ListNode* head) {
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

void printMatrix(vector<vector<int>>& matrix) {
	for (int i=0;i<matrix.size();i++) {
		printVector(matrix[i]);
	}
}
void printMatrix(vector<vector<char>>& matrix) {
    for (int i=0;i<matrix.size();i++) {
        printVector(matrix[i]);
    }
}

void printStack(stack<int> stk) {
    cout<<"[";
    while (!stk.empty()) {
        cout<<stk.top();
        stk.pop();
        if (!stk.empty()) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}
