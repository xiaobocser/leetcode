#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int longestConsecutive(vector<int> &num) {
        vector<vector<int>> hashTab(num.size());
        int remainder = 0,length = num.size();
        for(int i=0; i<length; i++){
            remainder = num[i] % length;
            cout << "re" << remainder << "num" << num[i] <<"ca"<<num[i]%3<< endl;
            if(remainder < 0)
                remainder += length;
            hashTab[remainder].push_back(num[i]);
            cout << remainder << "s" << hashTab[remainder].back() <<endl;
        }
        int max=0, maxTmp=0, number=0, pos=0;
        bool flag = false;
        for(int i=0; i<length; i++){
            if(!hashTab[i].empty()){
                number = hashTab[i].back();
                cout << number << "tt" << i <<endl;
                hashTab[i].pop_back();
                flag = true;
                pos = i;
                maxTmp = 1;
                while(flag){
                    pos = (pos+1) % length;
                    vector<int>::iterator result = find(hashTab[pos].begin(), hashTab[pos].end(), ++number);
                    if(result != hashTab[pos].end()){
                        maxTmp++;
                        hashTab[pos].erase(result);
                    }else{
                        flag = false;
                        number --;
                    }
                }

                number = number - maxTmp + 1;
                flag = true;
                pos = i;
                cout << number << "ss" << pos << endl;
                while(flag){
                    pos = (pos-1) % length;
                    if(pos < 0)
                        pos += length;
                    cout << "pos" << pos <<endl;
                    vector<int>::iterator result = find(hashTab[pos].begin(), hashTab[pos].end(), --number);
                    if(result != hashTab[pos].end()){
                        maxTmp++;
                        hashTab[pos].erase(result);
                    }else{
                        flag = false;
                        number ++;
                        if(max < maxTmp)
                           max = maxTmp;
                    }
                }
            }
        }
        return max;
    }

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(5);
    num.push_back(2);
    num.push_back(4);
    cout << longestConsecutive(num);
}


