#include<iostream>
#include<vector>
#include <string>

using namespace std;


int findMin(vector<int> &num) {
//    if(num[num.size()/2] > num[0] || num[num.size()/2] > num[num.size()-1] )
//        return num[0] < num[num.size()-1]? num[0]: num[num.size()-1];
    int front =0, back = num.size()-1, mid = 0;
    while(front < back-1){
        mid = (front + back) / 2;
        if(num[front] < num[back])
            back = mid;
        else
            front = mid;
    }
//    cout << num[back] << num[front];
    return num[back] < num[front] ? num[back] : num[front];
}


int calculate(int k, int n){
    int result = 1;
    for(int i=0; i<k; i++){
        result *= n - i;
    }
    for(int i=1; i<=k; i++){
        result /= i;
    }
    return result;
}

int minPathSum(vector<vector<int> > &grid) {
/*
    int rowCount = grid.size()-1;
    int colCount = grid[0].size()-1;
    return findMin(grid, 0, 0, rowCount, colCount);
*/
    int count = 2;
    int len = grid.size() + grid[0].size();
    int row,col;
    while(count < len){
        for(int i=0; i<count; i++){
            row = count - i -1;
            if( row >= grid.size() )
                continue;
            col = i;
            if(col >= grid[0].size())
                break;
            if(row-1 >= 0 && col-1 >= 0)
                grid[row][col] += (grid[row-1][col] < grid[row][col-1] ? grid[row-1][col] : grid[row][col-1]);
            else
            if(row-1 >= 0)
                grid[row][col] += grid[row-1][col];
            else
                grid[row][col] += grid[row][col-1];
        }
        count++;
    }
    return grid[grid.size()-1][grid[0].size()-1];
}


vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result;
    vector<int> tmp(n, 0);
    for(int i=0; i<n; i++){
        result.push_back(tmp);
        for(int j =0; j<result[i].size();j++)
            cout << result[i][j];
        cout << endl;
    }
    int len = n * n + 1, row = 0, col = 0, direction = 1;
    for(int i=1; i<len; i++){
        result[row][col] = i;cout << direction << row << col << endl;
        switch(direction){
            case 1:
                if(col+1 == n ){//|| result[row][col+1] != 0){
                    direction++;
                    row++;
                }else
                    col++;
            break;

            case 2:
                if(row+1 == n || result[row+1][col] != 0){
                    direction++;
                    col++;
                }else
                    row++;
            break;

            case 3:
                if(col-1 == -1 || result[row][col-1] != 0){
                    direction++;
                    row++;
                }else
                    col--;
            break;

            case 4:
                if(row-1 == -1 || result[row-1][col] != 0){
                    direction = 1;
                    col--;
                }else
                    row--;
            break;
        }
    }
    return result;
}

int maxArea(vector<int> &height) {
    int result = -1, tmp, max = -1;

    for(int i=0; i<height.size(); i++){
        if(max < height[i])
            max = height[i];
        else
            continue;
        for(int j=i+1; j<height.size(); j++){
            tmp = height[i] < height[j] ? height[i] : height[j];
            tmp *= j - i;
            if(result < tmp)
                result = tmp;
    }
    return result;
    }
}
int main(){
//    vector<int> num = {3, 4, 5, 1, 2};
//    cout << findMin(num);
//    cout << calculate(5,5);
//    vector<vector<int> > grid = {{1,2},{1,1}};
//    minPathSum(grid);
//    for(int i=0; i<grid.size(); i++){
//        for(int j=0; j<grid[0].size(); j++){
//            cout << grid[i][j];
//        }
//        cout <<endl;
//    }
//    vector<int> num(10);
//    cout << num[4];
//    generateMatrix(2);
//    string name(6,'(');
//    name[0] = '(';name[1] = ')';
//    cout << name;
//    int i = 0;
//    cout << (i == 1 ? i : 2);
//    string test;
//    test.push_back('a');test.push_back('b');test.pop_back();
//    cout << test;
    vector<int> number = {1,2,4,3};
    maxArea(number);
}
