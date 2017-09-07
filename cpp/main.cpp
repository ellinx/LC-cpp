#include "Solutions.hpp"
#include "main.h"

using namespace std;

vector<int> InitVectorInt(int array[], int n);
vector<string> InitVectorString(string array[], int n);
vector<Interval> InitVectorInterval(Interval array[], int n);
ListNode* InitListInt(int array[], int n);
vector<vector<int>> InitMatrixInt(int array[][MATRIX_INT_COL], int totalRow, int totalCol);
vector<vector<char>> InitMatrixChar(char array[][MATRIX_CHAR_COL],int totalRow, int totalCol);

int main() {
    Solutions dummy;
    vector<int> vec_int;
    vector<string> vec_string;
    vector<Interval> vec_interval;
	vector<vector<int>> matrix_int;
    vector<vector<char>> matrix_char;
	ListNode* list_int = NULL;
	ListNode* list_int2 = NULL;

    int nums[] = {3,1,4,2};
	int nums2[] = {5, 6, 4};
    
    string words[] = {"oath","pea","eat","rain"};

	int matrixInt[][MATRIX_INT_COL] = {
		{3, 4, 5},
		{3, 2, 6},
		{2, 2, 1}
	};
    
    char matrixChar[][MATRIX_CHAR_COL] = {
        /*{'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}*/
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    Interval intervals[] = {Interval(0,70),Interval(5,40),Interval(20,50),Interval(50,60)};
    
    //****** initialize inputs *****************************************************************
    vec_int = InitVectorInt(nums, sizeof(nums)/sizeof(nums[0]));
    vec_string = InitVectorString(words, sizeof(words)/sizeof(words[0]));
    vec_interval = InitVectorInterval(intervals, sizeof(intervals)/sizeof(intervals[0]));
    list_int = InitListInt(nums, sizeof(nums)/sizeof(nums[0]));
    list_int2 = InitListInt(nums2, sizeof(nums2)/sizeof(nums2[0]));
    matrix_int = InitMatrixInt(matrixInt, MATRIX_INT_ROW, MATRIX_INT_COL);
    matrix_char = InitMatrixChar(matrixChar, MATRIX_CHAR_ROW, MATRIX_CHAR_COL);
    //******************************************************************************************
    
    //******************* print inputs ******************************************************
    int input_type = INPUT_VEC_INT;
    
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
            printList(list_int2);
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
	int result = dummy.isMatchWildcard("aab", "c*a*b");
	cout<<"result is:"<<endl;
	
	
	//printMatrix(matrix_int);
    //printVector(result);
	cout<<result<<endl;
	//printList(result);
    return 0;
}


//Initialization functions
vector<int> InitVectorInt(int array[], int n) {
    vector<int> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }

    return res;
}

vector<string> InitVectorString(string array[], int n) {
    vector<string> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }

    return res;
}

vector<Interval> InitVectorInterval(Interval array[], int n) {
    vector<Interval> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }
    
    return res;
}

ListNode* InitListInt(int array[], int n) {
	
	ListNode* head = new ListNode(array[0]);
	ListNode* cur = head;

	for (int i=1;i<n;i++) {
		cur->next = new ListNode(array[i]);
		cur = cur->next;
	}

	return head;
}

vector<vector<int>> InitMatrixInt(int array[][MATRIX_INT_COL], int totalRow, int totalCol) {
	vector<int> row(totalCol, 0);
	vector<vector<int>> res(totalRow, row);

	for (int i=0;i<totalRow;i++) {
		for (int j=0;j<totalCol;j++) {
			res[i][j] = array[i][j];
		}
	}

	return res;
}

vector<vector<char>> InitMatrixChar(char array[][MATRIX_CHAR_COL],int totalRow, int totalCol) {
    vector<char> row(totalCol, '0');
    vector<vector<char>> res(totalRow, row);
    
    for (int i=0;i<totalRow;i++) {
        for (int j=0;j<totalCol;j++) {
            res[i][j] = array[i][j];
        }
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

void printVector(vector<Interval> & vec) {
    
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
