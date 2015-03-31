/*
Question: Combination Sum

	Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

	The same repeated number may be chosen from C unlimited number of times.

	Note:

		All numbers (including target) will be positive integers.
		Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
		The solution set must not contain duplicate combinations.

	For example, given candidate set 2,3,6,7 and target 7,
	A solution set is:
	[7]
	[2, 2, 3] 

Answer: DFS

notice that the path[] array and loop begin pos

*/


class Solution {
#define N 1000
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int path[N] = {0};
        int deep = 0;
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        for(int i=0; i<candidates.size(); i++){
            if(candidates[i] > target)
                break;
            path[deep] = candidates[i];
            if(candidates[i] == target)
                insertResult(path, deep+1, result);
            else
                DFS(candidates, target, path, deep+1, result, candidates[i], i);
        }
        return result;
    }
    
    void DFS(vector<int> &candidates, int &target, int path[N], int deep, vector<vector<int> > &result, int sum, int begin){
        
        for(int i=begin; i<candidates.size(); i++){
            sum += candidates[i];
            if(sum > target)
                break;
            
            path[deep] = candidates[i];
            if(sum == target)
                insertResult(path, deep+1, result);
            else
                DFS(candidates, target, path, deep+1, result, sum, i);
            
            sum -= candidates[i];
        }
    }
    
    void insertResult(int path[N], int deep, vector<vector<int> > &result){
        vector<int > tmp;
        for(int i=0; i<deep; i++)
            tmp.push_back(path[i]);
        result.push_back(tmp);
    }
};