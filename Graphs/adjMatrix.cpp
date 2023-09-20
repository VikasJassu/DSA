#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"enter no of nodes"<<endl;
    cin>>n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    int e;
    cout<<"enter no of edges"<<endl;
    cin>>e;

    

    for(int i=0; i<e; i++) {
        int u,v;
        cin>>u>>v;
        //mark enteries into matrix
        adj[u][v] = 1;
    }

    cout<<"printing matrix:"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cout<<adj[i][j]<<" ";
        } cout<<endl;
    }

}