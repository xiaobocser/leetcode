#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    char condition[1000][1000] = {0};
    int k, pos = 0, len = s.size(), exitFlag = 0;
    bool flag = false;

    for(int i=0; i<s.size(); i++) {
        condition[i][i] = 1;
        if(s[i] == s[i-1] && i) {
            condition[i-1][i] = 1;
            pos = i-1;
            len = 2;
        }
    }

    for(int i=2; i<s.size(); i++) {
        k = 0;
        flag = true;
        for(int j=i; j<s.size(); j++) {
            if(condition[k+1][j-1] == 1 && s[k] == s[j]) {
                condition[k][j] = 1;
                pos = k;
                len = j-k+1;
                flag = false;
            }
            k++;
        }
        if(flag) {
            if(++exitFlag == 2)
                break;
        }
        else
            exitFlag = 0;
    }

    if(pos == 0 && len == s.size())
        return s;
    else
        return s.substr(pos, len);
}

int main(){
    string s = "dsdsfsad";
    cout << longestPalindrome(s);
}
