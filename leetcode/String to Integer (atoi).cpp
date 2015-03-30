#include <iostream>

using namespace std;

int atoi(const char *str) {
    int result = 0, tmp, flagInt = -1;
    bool flag = true, extFlag = false;
    for(int i=0; str[i] != 0; i++) {
        if(str[i] == ' ')
            if(flag)
                continue;
            else
                break;
        flag = false;
        if(str[i] == '-'){
            if(flagInt == -1)
                flagInt = 0;
            else
                return 0;
            continue;
        }
        if(str[i] == '+'){
            if(flagInt == -1)
                flagInt = 1;
            else
                return 0;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
            break;
        tmp = str[i] - '0';
        if((2147483647-tmp)/10 < result){
            extFlag = true;
            break;
        }
        result = result*10 + tmp;
    }
    if(extFlag){
        if(flagInt == 0)
            result = -2147483648;
        else
            result = 2147483647;
    }else if(flagInt == 0)
            result = result * -1;
    return result;
}

int main()  {
    int m = 10522545459;
    int i = -2147483648;
    cout << i << endl;
}
