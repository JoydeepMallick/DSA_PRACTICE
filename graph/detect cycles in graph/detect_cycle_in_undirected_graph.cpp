#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> convertAdjList(int V, vector<vector<int>> &edges){
    //use 1 based indexing for clarity
    vector<vector<int>> adj(V+1);
    for(auto p : edges){
        int v1 = p[0], v2 = p[1];
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    return adj;
}


//////////////////////////// DFS style search/////////////////////////////////////////////
bool detectcycle(vector<vector<int>> &adj, int cur, int parent, int vis[]){
    vis[cur] = 1;
    for(auto adjnode : adj[cur]){
        if(!vis[adjnode]) {
            bool found = detectcycle(adj, adjnode, cur, vis);
            if(found) return true;
        }
        else if(adjnode != parent) return true;//already visited but not parent means cycle
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //edge list provided, convert to adjacency list
    vector<vector<int>> adj = convertAdjList(n, edges);
    int vis[n+1] = {0}; // nothing visited initially 
    bool found = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            found = detectcycle(adj, i, -1, vis);
            if(found) break;
        }
    }   

    if(!found) return "No";
    else return "Yes";
}
//////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// BFS style search//////////////////////////////
bool detectcycle(vector<vector<int>> &adj, int start, int vis[]){
    vis[start] = 1;
    queue<pair<int, int>> q; // pair {cur Vertex, prev Vertex}
    q.push({start, -1});//let start with vertex 1 and since no previous set it to -1

    while(!q.empty()){
        int cur = q.front().first;
        int cursparent = q.front().second;
        q.pop();

        for(auto adjnode : adj[cur]){
            if(!vis[adjnode]){
                vis[adjnode] = 1;//mark this node as visited
                q.push({adjnode, cur});
            }else if(adjnode != cursparent){//since it undirected
                //loop found
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //edge list provided, convert to adjacency list
    vector<vector<int>> adj = convertAdjList(n, edges);
    int vis[n+1] = {0}; // nothing visited initially 
    bool found = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            found = detectcycle(adj, i, vis);
            if(found) break;
        }
    }   

    if(!found) return "No";
    else return "Yes";
}
/////////////////////////////////////////////////////////////////////////////////