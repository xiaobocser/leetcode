#include <iostream>

using namespace std;


int Kfind(int array[], int lowPos, int highPos, int K){
    int first = lowPos;
    int last = highPos;
    int key = array[first];
    while(first < last){
        while(first<last && array[last]>=key)
            last--;
        array[first] = array[last];
        while(first<last && array[first]<=key)
            first++;
        array[last] = array[first];
    }
    array[first] = key;
    if(first == K-1)
        return first+1;
    if(lowPos < first && first > K-1)
        return Kfind(array, lowPos, first-1, K);
    if(first < highPos && first < K-1)
        return Kfind(array, first+1, highPos, K);
}

int main(){
    int array[] = {3,1,2,6,3,4};
    int K = 4;
    cout << "array is ";
    for(int i=0; i<6; i++)
        cout << array[i] << ",";
    cout << endl << "-----------------------" << endl;
    cout << "top" << K <<" is ";
    int pos = Kfind(array, 0, 5, K);

    for(int i=0; i<pos; i++)
        cout << array[i] << ",";
    cout << endl;
}
