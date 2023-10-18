#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<stack>
#include<set>
#include<limits.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction) {
        //direction == 0 means undirected graph
        //direction == 1 means directed graph
        adjList[u].push_back({v,wt});
        if(direction == 0) {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList() {
        for(auto i: adjList) {
            // cout<<"i.first->"<<i.first<<" "<<"i.second->"<<endl;
            cout<< i.first << "-> ";
            for(auto j: i.second) {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestPathBFS(int src, int dest) {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        //pehle first node push kro q mein
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int fNode = q.front();
            q.pop();

            for(auto nbr: adjList[fNode]) {
                if(!visited[nbr.first]) {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
            }
        }

        //ab dest se src tk phuncho to get shortest path

        // vector<int>ans;
        // int node = dest;
        // while(node != -1) {
        //     ans.push_back(node);
        //     node = parent[node]; 
        // }

        // reverse(ans.begin(), ans.end());

        // cout<<"Printing shortest path"<<endl;
        // for(auto i: ans) {
        //     cout<< i <<" ";
        // }
        // cout<<endl;
        stack<int>ans;
        int node = dest;
        while(node != -1) {
            ans.push(node);
            node = parent[node]; 
        }
        cout<<"using stack"<<endl;
        while(!ans.empty()) {
            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<endl;
    }

    void topoSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans) {
    visited[src] = true;

    for(auto nbr: adjList[src]) {
        if(!visited[nbr.first]) {
            topoSortDFS(nbr.first, visited, ans);
        }
    }
    ans.push(src);
    }

    void shortestPathDFS(int dest, stack<int> &topoOrder, int n) {
        int src = topoOrder.top();
        topoOrder.pop();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(auto nbr: adjList[0]) {
            if(dist[0] + nbr.second < dist[nbr.first]) {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while(!topoOrder.empty()) {
            int topElem = topoOrder.top();
            topoOrder.pop();

            for(auto neighbour: adjList[topElem]) {
                if(dist[topElem] != INT_MAX) {
                    if(dist[topElem] + neighbour.second < dist[neighbour.first]) {
                        dist[neighbour.first] = dist[topElem] + neighbour.second;
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            cout<<i<<"-> "<<dist[i]<<endl;
        }
    }

    void dijkstra(int src, int n) {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty()) {
            auto topElem = *(st.begin());
            int nodeDistance = topElem.first;
            int node = topElem.second;

            //remove element from set
            st.erase(st.begin());

            //neighbours nikalo
            for(auto nbr: adjList[node]) {
                if(nodeDistance  + nbr.second < dist[nbr.first]) {
                    //***isme node distance ka meaning hai uss node tk phunchne me lagne wala min distance.
                    //mujhe distance update karna hai
                    //finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    //if entry found then remove it
                    if(result != st.end()) {
                        st.erase(result);
                    } 
                    //now update in distance array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first)); 
                }   
            }
        }

        cout<<"printing ans:"<<endl;
        for(int i=0; i<n; i++) {
            cout<<dist[i]<<", ";
        } cout<<endl;
    }

    void bellmanFordAlgo(int n, int src) {
        //create distance array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // now run n-1 times relaxation
        for(int i=0; i<n-1; i++) {
            for(auto t:adjList) {
                for(auto nbr: t.second) {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        //check if -ve cycle is present or not
        bool negativeCycle = false;
        for(auto t:adjList) {
                for(auto nbr: t.second) {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        negativeCycle = true;
                    }
                }
            }

        cout<<"Printing distance array:"<<endl;
        for(auto i: dist) {
            cout<< i << " ";
        }
        cout<<endl;

        if(negativeCycle) cout<<"-ve cycle is present";
        else cout<<"-ve cycle is not present";
    }

    void floydWarshall(int n) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        //now firstly put diagonal values equal to 0
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }

        //now update remaining values in dist matrix
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;

                dist[u][v] = wt;
            }
        }
        //now calculate shortest distance using helper
        for(int helper=0; helper<n; helper++) {
            for(int src=0; src<n; src++) {
                for(int dest=0; dest<n; dest++) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]); 
                }
            }
        }

        cout<<"Printing answer of FLOYD-WARSHALL:"<<endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<dist[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);
    
    //g.addEdge(4,5,6,0);
  
    g.printAdjList();
    // int src = 0;
    // int dest = 4;
    // g.shortestPathBFS(src, dest);
    // stack<int> topoOrder;
    // unordered_map<int, bool> visited;
    // g.topoSortDFS(0, visited, topoOrder);

    // g.shortestPathDFS(3, topoOrder, 5);
    //g.dijkstra(6, 7);
    //g.bellmanFordAlgo(5,0);
    g.floydWarshall(4);
}