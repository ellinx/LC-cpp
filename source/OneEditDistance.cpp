#include "../Solutions.hpp"

using namespace std;

/***************** One Edit Distance *****************/
/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

bool Solutions::isOneEditDistance(string s, string t) {
    
    int diff=s.size()-t.size();
    if (diff>1 || diff<-1) return false;
    
    diff = 0;
    
    if (s.size()==t.size()) {
        int index=0;
        while(index<s.size()) {
            if (s[index]==t[index]) {
                index++;
            } else {
                diff++;
                if (diff>1) return false;
                index++;
            }
        }
        if (diff==1) return true;
        else return false;
    } else {
        int i=0;
        int j=0;
        while(i<s.size() || j<t.size()) {
            if (i==s.size() || j==t.size()) {
                diff++;
                if (diff==1) return true;
                else return false;
            }
                
            if (s[i]==t[j]) {
                i++;
                j++;
            } else {
                diff++;
                if (diff>1) return false;
                if (s.size()>t.size()) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        if (diff==1) return true;
        else return false;
    }
}
