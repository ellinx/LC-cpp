#include "Solutions.hpp"
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

    cout<<endl;

    //test code
	vector<string> result = dummy.restoreIpAddresses("0690");
    
    cout<<"################################################"<<endl;
	cout<<"result is:"<<endl;
	
    tester.print(result);

    return 0;
}

