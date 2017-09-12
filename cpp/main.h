//
//  main.h
//  AlgSolutions
//
//  Created by LXU on 8/21/17.
//  Copyright © 2017 LXU. All rights reserved.
//

#ifndef main_h
#define main_h


#define INPUT_MANUAL        (0)
#define INPUT_VEC_INT       (1)
#define INPUT_VEC_STR       (2)
#define INPUT_VEC_INTERVALS (3)
#define INPUT_LIST_INT		(4)
#define INPUT_MATRIX_INT	(5)
#define INPUT_MATRIX_CHAR	(6)

#define MATRIX_INT_ROW		(5)
#define MATRIX_INT_COL		(4)
#define MATRIX_CHAR_ROW		(3)
#define MATRIX_CHAR_COL		(4)


void printVector(vector<int>& vec);
void printVector(vector<char>& vec);
void printVector(vector<bool>& vec);
void printVector(vector<string>& vec);
void printVector(vector<pair<int,int>>& vec);
void printVector(vector<Interval>& vec);

void printList(ListNode* head);

void printMatrix(vector<vector<int>>& matrix_int);
void printMatrix(vector<vector<char>>& matrix_int);

void printStack(stack<int> stk);

#endif /* main_h */
