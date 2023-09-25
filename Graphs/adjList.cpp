#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;
template<typename T>


// class Graph{    
//     public: 
//         unordered_map<int, list<pair<int,int>> > adjList;

//     int addEdge(int u, int v, int weight, bool direction) {
//         //let direction->0 means undirected graph
//         //direction 1 means directed graph
//         //in case of directed graph
//         adjList[u].push_back({v, weight});
//         //in case of undirected graph
//         if(direction == 0){
//             adjList[v].push_back({u, weight});
//         }
//     }

//     void printAdjList() {
//         for(auto node: adjList) {
//             cout<<node.first<< "->";
//             for(auto neighbour: node.second) {
//                 cout<<"("<<neighbour.first<<","<<neighbour.second<<"),";
//             }
//             cout<<endl;
//         }
//     }
// };
class Graph{    
    public: 
        unordered_map<T, list<T> > adjList;

    int addEdge(T u, T v, bool direction) {
        //let direction->0 means undirected graph
        //direction 1 means directed graph
        //in case of directed graph
        adjList[u].push_back(v);
        //in case of undirected graph
        if(direction == 0){
            adjList[v].push_back(   u);
        }
    }

    void printAdjList() {
        for(auto node: adjList) {
            cout<<node.first<< "->";
            for(auto neighbour: node.second) {
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    void bfs(T src, unordered_map<int, bool> &visited) {
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";
            for(auto neighbours: adjList[frontNode]) {
                if(!visited[neighbours]){
                    q.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited) {
        cout<<src<<", ";
        visited[src] = true;

        for(auto neighbours: adjList[src]) {
            if(!visited[neighbours]){
                dfs(neighbours, visited);
            }
        }
    }

    //using BFS
    bool isCyclicUsingBFS(T src, unordered_map<int, bool> &visited) {
        queue<T> q;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for(auto nbr: adjList[frontNode]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    //cout<<"frontnode->"<<frontNode<<" - "<<"nbr->"<<nbr<<endl;
                    visited[nbr] = true;
                    parent[nbr] = frontNode; 
                }
                else{
                    //it means node is visited
                    if(nbr != parent[frontNode]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //using DFS
    bool isCyclicUsingDFS(int src, int parent, unordered_map<int, bool> &visited) {
        visited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                bool checkAageKaAns = isCyclicUsingDFS(nbr, src, visited);
                if(checkAageKaAns) return true; 
            }
            else{
                if(nbr != parent) return true;
            }
        }
        return false;
    }

    //directed graph mein DFS se cyclic check karna
    bool isCyclicInDirectedGraphDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                bool aageKaAns = isCyclicInDirectedGraphDFS(nbr, visited, dfsVisited);
                if(aageKaAns) return true;
            }
            else{
                if(visited[nbr] == true && dfsVisited[nbr] == true)
                    return true;
            }
        }
        //yaha pr hi galti hoti hai
        dfsVisited[src] = false;
        return false; 
    }

    bool isCyclicInDirectedGraphBFS(int n) {
        queue<int> q;
        unordered_map<int, int> indegree;
        vector<int> ans;

        for(auto i: adjList) {c
            int src = i.first;
            for(auto nbr: i.second) {
                indegree[nbr]++;
            }
        }


        for(int i=0; i<n; i++) {
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);
            for(auto nbr: adjList[fNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if(ans.size() == n) {
            return false;
        }
        else{
            return true;
        }
    }
    //topological sort using DFS
    void topoSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans) {
        visited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                topoSortDFS(nbr, visited, ans);
            }
        }
        //push into stack
        ans.push(src);
    }

    //Kahn's algorithm or toposort using BFS
    void topoSortBFS(int n, vector<int> &ans) {
        queue<int> q;
        unordered_map<int, int> indegree;
        //sabki indegree calc karo
        for(auto i: adjList) {
            int src = i.first;
            for(auto nbr: i.second) {
                indegree[nbr]++;
            }
        }

        for(int i=0; i<n; i++) {
            cout<<"i = "<<i<<" ";
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        //now apply bfs logic
        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);
            for(auto nbr: adjList[fNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) 
                    q.push(nbr);
            }
        }
    }
};
int main()
{
    Graph<int> g;
    //n is no of nodes in graph
    int n = 8;
    // g.addEdge(2,4,1);
    // g.addEdge(2,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,3,1);
    // g.addEdge(3,7,1);
    // g.addEdge(6,7,1);
   
    // g.addEdge(7,0,1);
    // g.addEdge(7,1,1);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);
    

    g.printAdjList();

    // unordered_map<int, bool> visited;
    // cout<<"Printing bfs"<<endl;
    // for(int i=0; i<n; i++){
    //     if(!visited[i]) {
    //         g.bfs(i, visited);  
    //     }
    // }
    // cout<<endl;
    // cout<<"Printing dfs"<<endl;
    // unordered_map<int, bool> visited2;
    // for(int i=0; i<n; i++) {
    //     if(!visited2[i]) {
    //         g.dfs(i, visited2);
    //     }
    // }
    // unordered_map<int, bool> visited;
    // bool ans = false;
    // for(int i=0; i<n; i++) {
    //     if(!visited[i]) {
    //         ans = g.isCyclicUsingBFS(i, visited);
    //         if(ans) break;
    //     }
    // }

    // if(ans)
    //     cout<<"Cycle is present in graph"<<endl;
    // else
    //     cout<<"Cycle is absent in graph"<<endl;


    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsVisited;
    // bool ansDFS = false;
    // for(int i=0; i<n; i++) {
    //     if(!visited[i]) {
    //         ansDFS = g.isCyclicInDirectedGraphDFS(i,visited, dfsVisited);
    //         if(ansDFS) break;
    //     }
    // }
    // if(ansDFS)
    //     cout<<"Cycle is present in graph"<<endl;
    // else
    //     cout<<"Cycle is absent in graph"<<endl;

    // unordered_map<int, bool> visited;
    // stack<int> ans;

    // for(int i=0; i<n; i++) {
    //     if(!visited[i]) {
    //         g.topoSortDFS(i, visited, ans);
    //     }
    // }

    // cout<<"Topo Sort: "<<endl;
    // while(!ans.empty()) {
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // } cout<<endl;
    // vector<int> ans;
    // g.topoSortBFS(n, ans);

    // cout<<"printing toposort using dfs"<<endl;
    // for(auto i: ans) {
    //     cout<< i << " ";
    // } cout<<endl;
    bool ans = g.isCyclicInDirectedGraphBFS(n);
    if(ans == true) {
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is absent"<<endl;
    }

}