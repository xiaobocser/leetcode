#include<iostream>

using namespace std;

long geneLong(string &a) {
    long result = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] == '1')
            result += (1 << (a.size() -i-1));
    }
    return result;
}

string geneBinary(long &a) {
    long t = 1;
    string res, re;
    while(t != 0){
        if(a % 2 != 0)
            res += '1';
        else
            res += '0';
        a = a/2;
        t = a;
    }
    for(int i=0; i<res.size(); i++)
        re += res[res.size()-i-1];
    return re;
}

string add(string &a, string &b){
    int localsum = 0, i;
    string res, result;
    for(i=0; i<a.size()&& i<b.size(); i++){
        if(a[a.size() -i-1] == '1' && b[b.size()- i-1] == '1')
            localsum += 2;
        else if(a[a.size() -i-1] == '1' || b[b.size()- i-1] == '1')
                localsum += 1;

        if(localsum%2 == 0)
            res += '0';
        else
            res += '1';
        localsum = localsum/2;
    }

    for(; i<a.size(); i++){
        if(a[a.size() -i-1] == '1')
            localsum += 1;

        if(localsum%2 == 0)
            res += '0';
        else
            res += '1';
        localsum = localsum/2;
    }

    for(; i<b.size(); i++){
        if(b[b.size()- i-1] == '1')
            localsum += 1;

        if(localsum%2 == 0)
            res += '0';
        else
            res += '1';
        localsum = localsum/2;
    }

    if(localsum == 1)
        res += '1';

    for(i=0; i<res.size(); i++)
        result += res[res.size()-i-1];

    return result;
}

string addBinary(string a, string b) {
    long a1 = geneLong(a);cout<<a1<<endl;
    long b1 = geneLong(b);cout<<b1<<endl;
    long res = a1+b1;
    cout << geneBinary(res) << endl;

    return add(a, b);
}

int main(){
    cout << (1%2)<<endl;
    cout << addBinary("1010", "1011");
    return 0;
}
