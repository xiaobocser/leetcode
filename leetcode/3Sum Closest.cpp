#include <iostream>


int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int closest = INT_MAX, len = num.size()-1, j, k, sum, dis, minDis = INT_MAX;
    for(int i=1; i<len; i++){
        j = i-1;
        k = i+1;
        while(j > -1 && k < num.size()){
            sum = num[j] + num[i] + num[k];
            dis = target - sum;
            if(dis > 0)
                k++;
            else if(dis < 0) {
                j--;
                dis = dis * -1;
            }
            else
                return target;

            if(dis < minDis) {
                closest = sum;
                minDis = dis;
            }
        }
    }
    return closest;
}


int main(){

}
