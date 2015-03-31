/*
Question: Combination Sum II

	Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

	Each number in C may only be used once in the combination.

	Note:

		All numbers (including target) will be positive integers.
		Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
		The solution set must not contain duplicate combinations.

	For example, given candidate set 10,1,2,7,6,1,5 and target 8,
	A solution set is:
	[1, 7]
	[1, 2, 5]
	[2, 6]
	[1, 1, 6] 

Answer: DFS and the diff with the I problem

	the diff is that the begin pos +1 in loop and num[i]==num[i-1] duplication detect

	notice that the path[] array and loop begin pos

*/


class Solution {
#define N 1000
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int path[N] = {0};
        int deep = 0;
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for(int i=0; i<num.size(); i++){
            if(i!=0 && num[i] == num[i-1])
                continue;
            if(num[i] > target)
                break;
            path[deep] = num[i];
            if(num[i] == target)
                insertResult(path, deep+1, result);
            else
                DFS(num, target, path, deep+1, result, num[i], i+1);
        }
        return result;
    }
    
    void DFS(vector<int> &num, int &target, int path[N], int deep, vector<vector<int> > &result, int sum, int begin){
        
        for(int i=begin; i<num.size(); i++){
            if(i!=begin && num[i] == num[i-1])
                continue;
            sum += num[i];
            if(sum > target)
                break;
            
            path[deep] = num[i];
            if(sum == target)
                insertResult(path, deep+1, result);
            else
                DFS(num, target, path, deep+1, result, sum, i+1);
            
            sum -= num[i];
        }
    }
    
    void insertResult(int path[N], int deep, vector<vector<int> > &result){
        vector<int > tmp;
        for(int i=0; i<deep; i++)
            tmp.push_back(path[i]);
        result.push_back(tmp);
    }
};