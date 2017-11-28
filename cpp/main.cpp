#include "Solutions.hpp"
#include "Tester.hpp"
#include <thread>


int main() {
    Solutions dummy;

    //inputs
    vector<int> vec_int = {5,6,3,1,2,4};
    vector<int> vec_int1 = {-2,-1};
    vector<int> vec_int2 = {-1,2};
    vector<int> vec_int3 = {0,2};
    vector<string> vec_string = {"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO","OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO","OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO","OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO","OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO","OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"};
    vector<pair<int,int>> vec_pair_int_int = {{10,16}, {2,8}, {1,6}, {7,12}};
    vector<Interval> vec_interval = {
        Interval(3,4),
        Interval(2,3),
        Interval(1,2)
    };
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
                            {'i', 'h', 'k', 'r'},*/
                            {'X','O','X','O','X','O'},
                            {'O','X','O','X','O','X'},
                            {'X','O','X','O','X','O'},
                            {'O','X','O','X','O','X'}
                        };
    
    ListNode* list_int = Tester::initListInt(vector<int>{1, 2, 6, 3, 4, 5, 6});
    ListNode* list_int2 = Tester::initListInt(vector<int>{5, 6, 4});
    
    
//    TreeNode* root = dummy.ConstructFromInorder(vec_int);

    cout<<endl;

    //test code
    auto result = dummy.isHappy(19);
    //dummy.reorderList(list_int);
    
    cout<<"################################################"<<endl;
	cout<<"result is:"<<endl;
	
    Tester::print(result);

    return 0;
}

