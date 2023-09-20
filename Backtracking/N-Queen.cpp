#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;

void printSolution(vector<vector<char>> &board , int n) {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cout<< board[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<char>> &board , int n , int row , int col) {

    if(rowCheck[row] == true)
        return false;

    if(upperLeftDiagonalCheck[n-1+col-row] == true) 
        return false;

    if(bottomLeftDiagonalCheck[row+col] == true)
        return false;   

    return true;         

    // int i = row;
    // int j = col;
    // //left side mein queen check karne k liye
    // while(j>=0) {
    //     if(board[i][j] =='Q') {
    //         return false;
    //     }
    //     j--;
    // }

    // //left upper side diagonally check karne le liye 
    //  i = row;
    //  j = col;

    // while(i>=0 && j>=0) {
    //     if(board[i][j] =='Q') {
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }

    // //left downside mein diagonally check karne k liye
    //  i = row;
    //  j = col;

    // while(i<n && j>=0) {
    //     if(board[i][j] =='Q') {
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }


    // return true;
}


void solution(vector<vector<char>> &board , int n , int col) {
    if(col >= n) {
        printSolution(board , n);
        return;
    } 
 
    for(int row=0 ; row<n ; row++) {
        if(isSafe(board , n , row , col)) {
            board[row][col] = 'Q';

            rowCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            bottomLeftDiagonalCheck[row+col] = true;

            solution(board , n ,col+1);

            board[row][col] = '-' ;

            
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            bottomLeftDiagonalCheck[row+col] = false;

        }
    }
   
}
int main()
{
    int n = 8;
    vector<vector<char>> board(n , vector<char>(n , '-'));

    int col = 0;

    solution(board , n , col);

}