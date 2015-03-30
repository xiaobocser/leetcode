/*

Question:

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 

Answer:

dp algorithm.

traverse string s from left to right
if valid for i; like
	pos = record[i] - 1 - record[i-1];
	record[i] = record[pos] + record[i-1] + 2

"()(()"

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        int max = 0, pos; 
        int *record = new int[s.size()];
        record[0] = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i] == '(')
                record[i] = 0;
            else{ // ')'
                pos = i - 1 - record[i-1];
                if(pos > -1){
                    if(s[pos] == '('){
                        record[i] = record[i-1] + 2;
                        if(pos > 0)
                            record[i] += record[pos-1];
                        if(record[i] > max)
                            max = record[i];
                    }else
                        record[i] = 0;
                }else
                    record[i] = 0;
            }
        }
        return max;        
    }
};