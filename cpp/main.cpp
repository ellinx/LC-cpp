#include "Solutions.hpp"

using namespace std;

void printVector(vector<int>& vec);
void printVector(vector<char>& vec);
void printVector(vector<string>& vec);
void printList(ListNode* head);
void printMatrix(vector<vector<int>>& matrix_int);
void printMatrix(vector<vector<char>>& matrix_int);

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

    int nums[] = {2, 4, 1, 2, 0, 1};
	int nums2[] = {5, 6, 4};
    
    string words[] = {"leet","code","cog"};

	int matrixInt[][MATRIX_INT_COL] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
    
    char matrixChar[][MATRIX_CHAR_COL] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    Interval intervals[] = {Interval(0,70),Interval(5,40),Interval(20,50),Interval(50,60)};
    
    int input_type = INPUT_MATRIX_CHAR;
    
    switch(input_type) {
        case INPUT_VEC_INT:
            cout<<"Input: ";
            vec_int = InitVectorInt(nums, sizeof(nums)/sizeof(nums[0]));
            break;
        case INPUT_VEC_STR:
            cout<<"Input: ";
            vec_string = InitVectorString(words, sizeof(words)/sizeof(words[0]));
            break;
        case INPUT_VEC_INTERVALS:
            cout<<"Input: ";
            vec_interval = InitVectorInterval(intervals, sizeof(intervals)/sizeof(intervals[0]));
            break;
		case INPUT_LIST_INT:
			cout<<"Input:"<<endl;
            list_int = InitListInt(nums, sizeof(nums)/sizeof(nums[0]));
			list_int2 = InitListInt(nums2, sizeof(nums2)/sizeof(nums2[0]));
			break;
		case INPUT_MATRIX_INT:
			cout<<"Input:"<<endl;
			matrix_int = InitMatrixInt(matrixInt, MATRIX_INT_ROW, MATRIX_INT_COL);
			break;
        case INPUT_MATRIX_CHAR:
            cout<<"Input:"<<endl;
            matrix_char = InitMatrixChar(matrixChar, MATRIX_CHAR_ROW, MATRIX_CHAR_COL);
            break;
        default:
            break;
    }
    

	bool result = dummy.exist(matrix_char, "ABCB");
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
    printVector(res);
    return res;
}

vector<string> InitVectorString(string array[], int n) {
    vector<string> res;
    for (int i=0;i<n;i++) {
        res.push_back(array[i]);
    }
    printVector(res);
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
	printList(head);
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
	printMatrix(res);
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
    printMatrix(res);
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
