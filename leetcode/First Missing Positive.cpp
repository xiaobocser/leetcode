/*
Question: Given an unsorted integer array, find the first missing positive integer.

    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.

    Your algorithm should run in O(n) time and uses constant space.

Answer: Array hash 

But a more effictive method is change the pos of every number in the array with one travel

*/

// better method

public int firstMissingPositive(int[] A)
{
	if(A.length==0||A==null)
	return 1;
	//把元素放入正确的位置，例如1放在A[0]，2放在A[1]...
	for(int i = 0;i<A.length;i++)
	{
		while(A[i]!=i+1)
		{
			if(A[i]>=A.length||A[i]<=0||A[i]==A[A[i]-1])
			  break;
			int temp = A[i];
			A[i] = A[temp-1];
			A[temp-1] = temp;
		}
	}

	for(int i = 0;i<A.length;i++)
	{
		if(A[i]!=i+1)
			return i+1;
	}
	return A.length+1;
}

// my method

#include<iostream>
using namespace std;
#define N 1000

int firstMissingPositive(int A[], int n) {
    int condition[N] = {0};
    for(int i=0; i<n; i++)
        if(A[i]>0)
            condition[(A[i]-1)>>5] = (1<<(A[i]-1)) | condition[(A[i]-1)>>5];
    int result = 1;
    for(int i=0; i<N; i++){
        if(condition[i] == 0)
            break;
        if(condition[i] == -1)
            result += 32;
        else{
            for(int j=0; j<32; j++){
                if(((1<<j) & condition[i] )== 0){
                    result += j;
                    break;
                }
            }
            break;
        }
    }
    return result;
}


int main(){
    int A[1000] = {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};
    int i=0;
    for(i=0; i<N; i++)
        if(A[i] == 98)
            break;
    cout << firstMissingPositive(A, i+1);
}
