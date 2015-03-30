#include <vector>
#include <iostream>

using namespace std;


string longestCommonPrefix(vector<string> &strs) {
    int i = 0, j = 0, min = INT_MAX, minPos;
    for(; i < strs.size(); i++){
        if(min > strs[i].size()){
            minPos = i;
            min = strs[i].size();
        }
    }
    string result = "";
    if(i == 0 || min == 0)
        return result;
    result = strs[minPos];
    for(i=0; i < strs.size(); i++){
        if(minPos == i)
            continue;
        for(j=0; j<strs[i].size() && j<result.size(); j++){
            if(strs[i][j] != result[j])
                break;
        }
        result = result.substr(0, j);
    }
    return result;
}



int main(){
    vector<string> strs;
    strs.push_back("caa");
    strs.push_back("");
    strs.push_back("a");
    strs.push_back("acb");
    cout << longestCommonPrefix(strs);
}
