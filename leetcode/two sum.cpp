#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    unordered_map<int, int> HSmap;
    int index1 = 0, index2 = numbers.size(), tmp;
    unordered_map<int, int>::const_iterator got;
    while(index1 < index2){
        HSmap.insert(pair<int, int>(numbers[index1], index1));
        index1++;
    }
    index1 = 0;
    while(index1 < index2){
        tmp = target - numbers[index1];

        got = HSmap.find(tmp);
        if( got != HSmap.end() && got->second != index1){
            result.push_back(index1+1);
            result.push_back(got->second+1);
            cout << index1 << "||" << got->second << endl;
            return result;
        }
        index1++;
    }
}

int main(){
    vector<int> numbers = {3,2,4};
    vector<int> result = twoSum(numbers,6);
    cout << result[0] << "::" << result[1];
}
