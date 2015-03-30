class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = 0, high = n-1, mid;
        vector<int> result;
        while(low < high){
            mid = low + (high - low)/2;
            A[mid] < target ? low = mid+1: high = mid;
        }
        if(A[low] != target){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(low);
        
        low = 0, high = n-1;
        while(low < high){
            mid = low + (high - low)/2;
            A[mid] > target ? high = mid: low = mid+1; 
        }
        if(A[low] != target)
            result.push_back(low-1);
        else
            result.push_back(low);
        return result;
    }
};