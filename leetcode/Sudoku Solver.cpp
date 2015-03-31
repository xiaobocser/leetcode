/*
Question : Sudoku Solver

    Write a program to solve a Sudoku puzzle by filling the empty cells.

    Empty cells are indicated by the character '.'.

    You may assume that there will be only one unique solution.

Answer: Recursion

notice that the pos of condition Array, especially the j pos

*/


#include<iostream>
#include<vector>

using namespace std;
void out(vector<vector<char> > &board);
void outTmp(char tmpRec[9]);
void outRecord(char record[27][9]);


int findPos(int &i, int &j){
    return 18+(i/3)*3 + j/3;
}

void creSu(char record[27][9], int &i, int &j, char tmpRec[9]){
    int m;
    for(m = 0; m<9; m++)
        if(record[i][m] == 1)
            tmpRec[m] = 1;
    for(m = 0; m<9; m++)
        if(record[j+9][m] == 1)
            tmpRec[m] = 1;

    int pos = findPos(i, j);
    for(m = 0; m<9; m++)
        if(record[pos][m] == 1)
            tmpRec[m] = 1;
}

bool checkBoard(vector<vector<char> > &board, int i, int j){
    for(; i<board.size(); i++){
        for(j=0; j<board.size(); j++){
            if(board[i][j] == '.')
                return false;
        }
    }
    return true;
}

void backSu(int &i, int &j){
    if(j == 0){
        i--;
        j=8;
    }else
        j--;
}

void moveSu(int &i, int &j){
    if(j == 8){
        i++;
        j=0;
    }else
        j++;
}

void recSu(char record[27][9], int &i, int &j, int &m, char tmpRec[9]){
    record[i][m] = 1;
    record[j+9][m] = 1;
    int pos = findPos(i, j);
    record[pos][m] = 1;
    tmpRec[m] = 1;
}

void backRecSu(char record[27][9], int &i, int &j, int &m, char tmpRec[9]){
    record[i][m] = 0;
    record[j+9][m] = 0;
    int pos = findPos(i, j);
    record[pos][m] = 0;
    tmpRec[m] = 0;
}

bool buildSudoku(vector<vector<char> > &board, char record[27][9], int i, int j) {
    if(board[i][j] != '.'){
        moveSu(i, j);
        return buildSudoku(board, record, i, j);
    }else{
        char tmpRec[9] = {0};
        creSu(record, i, j, tmpRec);
        for(int m=0; m<9; m++){
            if(tmpRec[m] == 0){
                board[i][j] = m + '1';//cout<< "forward  " << i << "  == " << j << "  == " << board[i][j] << endl;
                if(checkBoard(board, i, j) == true)
                    return true;
                recSu(record, i, j, m, tmpRec);
                moveSu(i, j);
//outTmp(tmpRec);out(board);getchar();
                if(buildSudoku(board, record, i, j) == true)
                    return true;

                backSu(i, j);
                backRecSu(record, i, j, m, tmpRec);
                board[i][j] = '.';//cout<< "backward  " << i << "  == " << j << "  == " << board[i][j] << endl;
            }
        }
        return false;
    }
}


void solveSudoku(vector<vector<char> > &board) {
    char record[27][9] = {0};
    int i, j;
    for(i=0; i<board.size(); i++){
        for(j=0; j<board[i].size(); j++){
            if(board[i][j] == '.')
                continue;

            record[j+9][ board[i][j] - '1' ] = 1;
            record[i][ board[i][j] - '1' ] = 1;
        }
    }

    int row = 0, col = 0;
    for(i=0; i<board.size(); i++){
        row = (i/3)*3;
        col = (i*3)%board.size();
        for(j=0; j<9; j++){
            if(board[row + j/3][col + j%3] == '.')
                continue;

            record[i+18][ board[row + j/3][col + j%3] - '1' ] = 1;
        }
    }

 //   outRecord(record);

    buildSudoku(board, record, 0, 0);
}

/*
    upwards is the leetcode code
    downward is the main cpp for tesing

*/

void out(vector<vector<char> > &board){
    for(int i=0 ;i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            cout << board[i][j] << " ";
        cout <<endl;
    }
}

void outTmp(char tmpRec[9]){
    for(int j=0; j<9; j++)
        if(tmpRec[j] == 1)
            cout << (j+1) << " ";
    cout <<endl;
}

void outRecord(char record[27][9]){
    for(int i=0 ;i<27; i++){
        for(int j=0; j<9; j++)
            if(record[i][j] == 1)
                cout << (j+1) << " ";
        cout <<endl;
    }
}

void construct(char tmp[9], vector<vector<char> > &board){
    vector<char> a;
    for(int i=0; i<9; i++)
        a.push_back(tmp[i]);
    board.push_back(a);
}

int main(){
    vector<vector<char> > board ;
    construct("..9748...", board);
    construct("7........", board);
    construct(".2.1.9...", board);
    construct("..7...24.", board);
    construct(".64.1.59.", board);
    construct(".98...3..", board);
    construct("...8.3.2.", board);
    construct("........6", board);
    construct("...2759..", board);

    out(board);
    cout << "----------------------" << endl;
    solveSudoku(board);

    out(board);
    return 0;
}

