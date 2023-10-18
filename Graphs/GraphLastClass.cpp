#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction) {
            //direction 0 means indirected graph
            //direction 1 means directed graph
            adjList[u].push_back(v);
            if(direction == 0) {
                adjList[v].push_back(u);
            }
        }

        //same topoSort ka code
        void dfs1(int src, stack<int> &s, unordered_map<int, bool> &visited) {
            visited[src] = true;

            for(auto nbr: adjList[src]) {
               if(!visited[nbr]) {
                    dfs1(nbr, s, visited);
               }
            }
            s.push(src);
        }

        void dfs2(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew) {
            visited[src] = true;
            cout<<src<<", ";
            for(auto nbr: adjNew[src]) {
                if(!visited[nbr]) {
                    dfs2(nbr, visited, adjNew);
                }
            }
            
        }

        // SCC is strongly connected component
        int countSCC(int n) {
            stack<int> s;
            unordered_map<int, bool> visited;
            int count = 0;

            //sabse pehle topoOrder nikalo
            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    dfs1(i, s, visited);
                }
            }
            //now reverse adjList ka edges
            //worst case mein iski compelxity n2 ho sakti hai but bhut jagah ye v + e bhi likhi hui mil jati hai

            unordered_map<int, list<int>> adjNew;
            for(auto t: adjList) {
                for(auto nbr: t.second) {
                    int u = t.first;
                    int v = nbr;
                    adjNew[v].push_back(u); 
                }
            }

            // count no of SCC here
            unordered_map<int, bool> visited2;
            while(!s.empty()) {
                int node = s.top();
                s.pop();
                
                if(!visited2[node]) {
                    cout<<"Printing "<<count+1<<"th component: ";
                    dfs2(node, visited2, adjNew);
                    cout<<endl; 
                    count++;
                }
                
            }
            return count;
        }

        //tarjan's algorithm to find no of bridges
        // tin -> insertion time
        // low -> lowest insertion time
        void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis) {
            vis[src] = true;
            tin[src] = timer;
            low[src] = timer;
            timer++;
            
            for(auto nbr: adjList[src]) {
                cout<<"nbr->"<<nbr<<endl;
                cout<<"parent->"<<parent<<endl;
                if(nbr == parent) {
                    cout<<"skipped nbr->"<<nbr<<endl;
                    cout<<"skipped parent->"<<parent<<endl;
                    continue;
                }
                if(!vis[nbr]) {
                    //dfs call kro
                    findBridges(nbr, src, timer, tin, low, vis);
                    //low update
                    low[src] = min(low[src], low[nbr]); //is condition mein mistake hoti hai
                    //check for bridge
                    if(low[nbr] > tin[src]) { //is condition mein mistake hoti hai
                        cout<<nbr<<"--"<<src<<" is a bridge"<<endl;
                    }
                }
                else{
                    //if node is not parent and visited also 
                    low[src] = min(low[src], low[nbr]);
                }
            }

        }


};

int main()
{
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(2,1,0);
    g.addEdge(1,3,0);
    g.addEdge(1,4,0);
    g.addEdge(1,6,0);
    g.addEdge(3,5,0);
    g.addEdge(4,5,0);


    // g.addEdge(4,5,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,4,1);
    // g.addEdge(6,7,1);

    // int ans = g.countSCC(8);
    // cout<<"No of SCC: "<<ans<<endl;
    int n = 7; //n is no of nodes
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    g.findBridges(0, -1, timer, tin, low, vis);
}