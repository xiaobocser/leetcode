#include <iostream>
#include <memory.h>

using namespace std;

int main(){
    char p[] = "dsdsadsadsadagf";
    //wrong case
    //char p[] = "dsdsadsadsadagf";
    memset(p, 'T', 5);
    cout << p;
}
