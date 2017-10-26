#include "Solutions.hpp"
#include "Tester.hpp"


int main() {
    Solutions dummy;

    //inputs
    vector<int> vec_int = {3, 10, 5, 25, 2, 8};
    vector<int> vec_int2 = {1,2,3};
    vector<string> vec_string = {"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO","OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO","OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO","OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO","OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO","OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"};
    vector<pair<int,int>> vec_pair_int_int = {{7,0}};
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
                            {'i', 'h', 'k', 'r'},*/
                            {'X','O','X','O','X','O'},
                            {'O','X','O','X','O','X'},
                            {'X','O','X','O','X','O'},
                            {'O','X','O','X','O','X'}
                        };
    
    ListNode* list_int = Tester::initListInt(vector<int>{1, 5, 3, 4, 9, 2});
    ListNode* list_int2 = Tester::initListInt(vector<int>{5, 6, 4});
    
    
//    TreeNode* root = dummy.ConstructFromInorder(vec_int);

    cout<<endl;

    //test code
    auto result = dummy.originalDigits("ereth");
    //dummy.reorderList(list_int);
    
    cout<<"################################################"<<endl;
	cout<<"result is:"<<endl;
	
    Tester::print(result);

    return 0;
}

