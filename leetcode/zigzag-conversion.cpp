#include <iostream>

using namespace std;

string convert(string s, int nRows) {
    if(s.empty() || s.size() == 1 || nRows == 1)
        return s;
    int front, back;
    bool flag ;
    int len = (nRows<<1) - 2;
    string result;
    for(int i=0; i<nRows; i++) {
        back = i<<1;
        front = len - back;
        if(back == 0)
            back = front;
        if(front == 0)
            front = back;
        flag = true;
        for(int j=i; j<s.size(); ) {
            result += s[j];
            if(flag){
                j += front;
                flag = false;
            }else{
                j += back;
                flag = true;
            }
        }
    }
    return result;
}



int main(){
    string s = "AB";
    cout << convert(s,2);
}
