#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;



void put(int i, int j, int l, int k, vector<vector<int> > &result) {
    int m=0;
    for(; m<result.size(); m++){
        if(i == result[m][0] && j == result[m][1] && l == result[m][2])
            break;
    }
    if(m == result.size()) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(j);
        tmp.push_back(l);
        tmp.push_back(k);
        result.push_back(tmp);
    }
}

vector<vector<int> > fourSum(vector<int> &num, int target) {

    vector<vector<int> > result;
    if(num.size() < 4)
        return result;
    sort(num.begin(), num.end());
    int min = num[0], max = num[num.size()-1];

    int i, j, k, l, tmp;

    for(i=1; i<num.size()-2; i++) {
        for(l = i+1; l<num.size()-1; l++) {
            j = i-1;
            k = l+1;
            tmp = target - (num[i] + num[l]);
            while(j>-1 && k<num.size()) {
                if(num[j] + num[k] > tmp)
                    j--;
                else if(num[j] + num[k] < tmp)
                    k++;
                else{
                    put(num[j], num[i], num[l], num[k], result);
                    j--;
                    k++;
                }
            }
        }
    }

    return result;
}


int main() {
    vector<int> tmp = {2,1,0,-1};
    vector<vector<int> > tt = fourSum(tmp, 2);
    for(int i=0; i<tt.size(); i++){
        for(int j=0; j<tt[i].size(); j++)
            cout << tt[i][j] << ",";
        cout << endl;
    }

}
