
#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Longest Absolute File Path *****************/
/*
 Suppose we abstract our file system by a string in the following manner:
 
 The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 
 dir
     subdir1
     subdir2
         file.ext
 The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
 
 The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
 
 dir
     subdir1
         file1.ext
         subsubdir1
     subdir2
         subsubdir2
             file2.ext
 The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
 
 We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
 
 Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
 
 Note:
     The name of a file contains at least a . and an extension.
     The name of a directory or sub-directory will not contain a ..
 Time complexity required: O(n) where n is the size of the input string.
 
 Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 
 */

int Solutions::lengthLongestPath(string input) {
    if (input.empty()) return 0;
    vector<pair<string,int>> path;
    int maxLength = 0;
    int index = 0;
    while (index<input.size()) {
        if (input[index]=='\n') {
            int tab = 0;
            int i=0;
            //find how many tabs
            for (i=1;input[index+i]=='\t';i++) {
                tab++;
            }
            cout<<"tabs="<<tab<<endl;
            index += i;
            int end = index+1;
            bool isFile = false;
            //find end of current dir or file
            while (end<input.size()) {
                if (input[end]=='.')
                    isFile = true;
                if (input[end]=='\n')
                    break;
                
                end++;
            }
            //adjust path to add current dir or file
            cout<<"path size="<<path.size()<<endl;
            while (tab!=path.size()) {
                path.pop_back();
            }
            
            //process current dir or file
            string s = input.substr(index,end-index);
            int curLength = 0;
            if (path.empty()) {
                curLength = s.size();
            } else {
                curLength = path.back().second+1+s.size();
            }
            path.push_back(pair<string,int>(s,curLength));
            if (isFile) {
                maxLength = max(maxLength, path.back().second);
            }
            index = end;
        } else {
            if (input[index]=='.') {
                //there is only one file in the system
                return input.size();
            }
            index++;
            if (index<input.size() && input[index]=='\n') {
                string s = input.substr(0,index);
                path.push_back(pair<string,int>(s, s.size()));
            }
            
        }
        Tester::print(path);
    }
    if ("a\tb"=="a    b") cout<<"four spaces are treated as a tab"<<endl;
    return maxLength;
}
