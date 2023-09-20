#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y ,int row , int col, int arr[3][3] , vector<vector<bool>> &visited) {
    if((((x>=0) && (x<row)) &&( (y>=0) && (y<col)) ) 
      && (arr[x][y] == 1) 
      && (visited[x][y] == false)) {
        return true;
    }
    else {
        return false;
    }
}

void solveMaze(int arr[3][3] , int row , int col , vector<vector<bool>> &visited , int i , int j , vector<string> &path , string output)
{
    //base case
    if( i == row-1 && j == col-1) {
        path.push_back(output);
        return;
    }

    //Down
     if(isSafe(i+1 , j , row , col ,arr , visited)) {
        visited[i+1][j] = true;
        solveMaze(arr,row,col,visited,i+1,j,path,output + 'D');
        //backtracking
        visited[i+1][j] = false;
     }
    //Left
    if(isSafe(i , j-1 , row , col ,arr , visited)) {
        visited[i][j-1] = true;
        solveMaze(arr,row,col,visited,i,j-1,path,output + 'L');
        //backtracking
        visited[i][j-1] = false;
     }
    //Right
    if(isSafe(i , j+1 , row , col ,arr , visited)) {
        visited[i][j+1] = true;
        solveMaze(arr,row,col,visited,i,j+1,path,output + 'R');
        //backtracking
        visited[i][j+1] = false;
     }
    //Up
    if(isSafe(i-1 , j , row , col ,arr , visited)) {
        visited[i-1][j] = true;
        solveMaze(arr,row,col,visited,i-1,j,path,output + 'U');
        //backtracking
        visited[i-1][j] = false;
     }
}
int main()
{
    int maze[3][3] ={ {1,0,0} , {1,1,0} , {1,1,1} };
    int row = 3;
    int col = 3;

    //if first element or source is 0 then 
    if(maze[0][0] == 0) {
        cout<<"no path exists"<<endl;
        return 0;
    }

    vector<vector<bool>> visited(row , vector<bool> (col , false));
    
    visited[0][0] = true;
    vector<string> path;
    string output = "";

    solveMaze(maze , row , col , visited , 0 , 0 , path , output);

    cout<<"printing all results "<<endl;
    for(auto i: path) {
        cout<< i <<" ";
    }
    cout<<endl;

    if(path.size() == 0) {
        cout<<"no path exists"<<endl;
    }


    return 0;
}