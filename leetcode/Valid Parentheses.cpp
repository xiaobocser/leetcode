#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<int> mystack;
    int val, tmp;
    for(int i=0; i<s.size(); i++) {
        switch(s[i]){
            case '(':val = -1;break;
            case ')':val =  1;break;
            case '{':val = -2;break;
            case '}':val =  2;break;
            case '[':val = -3;break;
            case ']':val =  3;break;
        }
        if(val < 0)
            mystack.push(val);
        else{
            if(mystack.empty())
                return false;
            tmp = mystack.top();
            if((val+tmp) == 0)
                mystack.pop();
            else
                return false;
        }
    }
    if(!mystack.empty())
        return false;
    return true;
}


int main(){
    string s = "([)]";
    cout << isValid(s);
}
