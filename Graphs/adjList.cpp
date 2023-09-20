#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
};
int main()
{
    Graph<int> g;
    //n is no of nodes in graph
    int n = 8; // yha pr question h n=7 ya 8 h.
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    g.printAdjList();

    unordered_map<int, bool> visited;
    for(int i=0; i<=n; i++){
        if(!visited[i]) {
            g.bfs(i, visited);  
        }
    }
}