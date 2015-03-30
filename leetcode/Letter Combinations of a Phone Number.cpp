#include <iostream>
#include <vector>

using namespace std;


void build(vector<string> &result, string &digits, int deep, string pre, vector<string > &map) {
    int pos = digits[deep] - '0';
    string tmpStore = pre;

    if(deep == digits.size()-1){
        for(int i=0; i<map[pos].size(); i++){
            pre += map[pos][i];
            result.push_back(pre);
            pre = tmpStore;
        }
    }else{
        for(int i=0; i<map[pos].size(); i++){
            pre += map[pos][i];
            build(result, digits, deep+1, pre, map);
            pre = tmpStore;
        }
    }
}



vector<string> letterCombinations(string digits) {

    vector<string > map;
    map.push_back(" ");
    map.push_back("O");
    map.push_back("abc");
    map.push_back("def");
    map.push_back("ghi");
    map.push_back("jkl");
    map.push_back("mno");
    map.push_back("pqrs");
    map.push_back("tuv");
    map.push_back("wxyz");

    vector<string> result;
    int deep = 0;
    string pre;
    build(result, digits, deep, pre, map);
    return result;
}



int main() {
    string digits = "232";
    vector<string> res = letterCombinations(digits);
    for(int i=0; i<res.size(); i++)
        cout << res[i] << endl;
}
