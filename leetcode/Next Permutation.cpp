#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &num, int begin) {
    int low = begin, high = num.size()-1, tmp;
    while(low < high){
        tmp = num[low];
        num[low] = num[high];
        num[high] = tmp;
        low ++;
        high --;
    }
}

void nextPermutation(vector<int> &num) {

    int i, j, tmp;
    for(i = num.size()-1; i>0; i--){
        if(num[i] > num[i-1])
            break;
    }
    if(i == 0){
        reverse(num, 0);
        return;
    }

    i--;

    for(j = num.size()-1; j>0; j--){
        if(num[j] > num[i])
            break;
    }

    tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;

    reverse(num, i+1);
}

int main(){
    vector<int> num = {1};
    nextPermutation(num);
    for(int i=0; i<num.size(); i++)
        cout << num[i] << " ";
}
