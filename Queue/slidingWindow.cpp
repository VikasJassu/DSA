#include<iostream>
#include<queue>
using namespace std;

void solve(int arr[], int n, int k) {

     queue<int> q;

    //processing first window's negative int
     for(int i = 0; i < k; i++) {
        if(arr[i] < 0) {
            q.push(i);
        }
     }


     for(int i = k; i < n; i++) {
        //previous window ka answer print
        if(q.empty()) {
            cout<< 0 <<" "; 
        }
        else{
            cout<< arr[q.front()] << " ";
        }

        //removing out of window element

        while ((!q.empty()) && (i - q.front() >= k) )
        {
            q.pop();
        }

        //inserting new element
        if(arr[i] < 0 ) {
            q.push(i);
        }
        
     }
     //inserting negative of last window
      if(q.empty()) {
            cout<< 0 <<" "; 
        }
        else{
            cout<< arr[ q.front()] << " ";
        }
}

int main()
{
    int arr[] = {12,-1,-7,8,-15,30,28,3};
    int size = 8;

    int k = 3;

    solve(arr,size,k);
}