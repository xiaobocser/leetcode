/*
Question :  Given n non-negative integers representing an elevation map where the width of each bar is 1, 
		    compute how much water it is able to trap after raining.

		For example,
		Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


		The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
		In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!


Answer  :   second-max value decide the ability of traping water

*/


class Solution {
public:
    int trap(int A[], int n) {
        int i, j, result=0, sum=0, secMax = 0, secPos = 0, record, rePos;
        for(i=0; i<n; i++)
            if(A[i] != 0)
                break;
                
        for(; i<n; i=j){
            record = A[i];
            sum = 0;
            secMax = secPos = 0;
            for(j=i+1; j<n; j++){
                if(A[j] >= record){
                    result += record*(j-i-1) - sum;
                    break;
                }
                else{
                    if(secMax < A[j]){
                        secMax = A[j];
                        secPos = j;
                    }
                    sum += A[j];
                }
            }
            if(j == n){
                sum = 0;
                for(j=i+1; j<n; j++){
                    if(A[j] == secMax)
                       break;
                   sum += A[j];
                }
                result += secMax*(j-i-1) - sum;
            }
        }
        return result;
    }
};