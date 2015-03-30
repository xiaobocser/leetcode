#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


void put(int i, int j, int k, vector<vector<int> > &result) {
    int m=0;
    for(; m<result.size(); m++){
        if(i == result[m][0] && j == result[m][1])
            break;
    }
    if(m == result.size()) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(j);
        tmp.push_back(k);
        result.push_back(tmp);
    }
}

vector<vector<int> > threeSum(vector<int> &num) {

    vector<vector<int> > result;
    if(num.size() < 3)
        return result;
    sort(num.begin(), num.end());
    int min = num[0], max = num[num.size()-1];
    if(min> 0 || max < 0)
        return result;

    int i, j, k, tmp;

    for(i=1; i<num.size()-1; i++) {
        j = i-1;
        k = i+1;
        tmp = -1 * num[i];
        while(j>=0 && k<num.size()){
            if(num[j] + num[k] > tmp)
                j--;
            else if(num[j] + num[k] < tmp)
                k++;
            else{
                put(num[j], num[i], num[k], result);
                j--;
                k++;
            }
        }
    }

    return result;
}



int main() {
 //   vector<int> tmp = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<int> tmp = {3,0,-2,-1,1,2};
/*    sort(tmp.begin(), tmp.end());
    for(int i=0; i<tmp.size(); i++)
        cout << tmp[i];
*/
    vector<vector<int> > tt = threeSum(tmp);
    for(int i=0; i<tt.size(); i++){
        for(int j=0; j<tt[i].size(); j++)
            cout << tt[i][j] << ",";
        cout << endl;
    }
}
