#include <iostream>
#include <vector>

using namespace std;

bool isMatchNew(const char *s, const char *p) {
    if(p[0] == 0) {
        if(s[0] == 0)
            return true;
        else
            return false;
    }
    int i, j, pPos = 0, row = 1, vLen = 0, vRow = 0;
    bool resultFlag = true;
    // construct vector
    for(; s[vLen] != 0; vLen++){}
    vLen++;
    for(; p[vRow] != 0; vRow++){}

    char **DPVector = new char*[vRow];
    for(int i=0; i<vRow; i++){
        DPVector[i] = new char[vLen];
    }
    for(int i=0; i<vRow; i++){
        for(int j=0; j<vLen; j++)
           DPVector[i][j] = 0;
    }

    //initialize
    if(p[1] !=0 && p[1] == '*'){
        if(p[0] == '.')
            for(i = 0; i < vLen; i++)
                DPVector[0][i] =  1;
        else{
            DPVector[0][0] = 1;
            for(i = 1; i < vLen; i++)
                if(p[0] == s[i-1])
                    DPVector[0][i] = 1;
                else
                    break;
        }
        pPos += 2;
    }else{
        if(p[0] == '.' || p[0] == s[0])
            DPVector[0][1] = 1;
        else
            resultFlag = false;
        pPos += 1;
    }
    if(p[pPos] == 0 && !s[1] == 0)
        resultFlag = false;

    //construct DPCondition
    bool rowFlag = true;

    while(p[pPos] != 0 && resultFlag){
        rowFlag = false;

        if(p[pPos+1] !=0 && p[pPos+1] == '*'){
            if(p[pPos] == '.'){
                for(i=0; i<vLen; i++){
                    if(DPVector[row-1][i] == 1){
                        for(; i<vLen; i++){
                            DPVector[row][i] =  1;
                        }
                    }
                }
            }
            else{
                for(i=0; i<vLen; i++){
                    if(DPVector[row-1][i] == 1){
                        DPVector[row][i] = 1;

                        for(j = i+1; j < vLen; j++){
                            if(p[pPos] == s[j-1])
                                DPVector[row][j] = 1;
                            else
                                break;
                        }
                    }
                }
            }
            rowFlag = true;
            pPos += 2;
        }else{
            for(i=1; i<vLen; i++){
                if( DPVector[row-1][i-1] == 1 && (p[pPos] == '.' || p[pPos] == s[i-1]) ){
                    DPVector[row][i] = 1;
                    rowFlag = true;
                }
            }
            pPos += 1;
        }
        // row satisfy or not
        if(!rowFlag){
            resultFlag = false;
            break;
        }
        // jump to next row
        row ++;
    }

    if(rowFlag && DPVector[row-1][vLen-1] == 1)
        resultFlag = true;
    else
        resultFlag = false;

    for(int i=0; i<row; i++){
        for(int j=0; j<vLen; j++)
            cout << (int)DPVector[i][j] << " ";
        cout << endl;
    }

    for(i=0; i<vRow; i++){
        delete []DPVector[i];
    }
    delete DPVector;
    return resultFlag;
}

int main(){
/*
    char *s = "abccccbc";
    char *p = "abc*bc";

    char *s = "aa";
    char *p = "aa";

    char *s = "aaa";
    char *p = "aa";

    char *s = "ab";
    char *p = ".*c";

    char *s = "aa";
    char *p = "a*";

    char *s = "a";
    char *p = "ab*";

    char *s = "ab";
    char *p = ".*..c*";

    char *s = "";
    char *p = ".*";
*/
    char *s = "a";
    char *p = "..*";

    cout << isMatchNew(s, p) << endl;

/*  TEST NEW 2 dimention vector

    int mm = 10;
    char **DPVector = new char*[mm];
    for(int i=0; i<10; i++){
        DPVector[i] = new char[mm];
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
           DPVector[i][j] = 0;
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            cout << DPVector[i][j];
        cout << endl;
    }

    for(int i=0; i<10; i++){
        delete []DPVector[i];
    }
    delete DPVector;
*/
}
