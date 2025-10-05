// problem link : https://leetcode.com/problems/critical-connections-in-a-network/

// Blog related to articulation point and bridge : https://codeforces.com/blog/entry/71146


class Solution {
private:
    int timer = 0; // counts the first insertion time in DFS
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges){
        vis[node] = 1;
        //initially both time are same
        tin[node] = low[node] = timer;

        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);//this happens in future if some old ancestor is incurred after backtracking
                if(low[it] > tin[node]){
                    //important edge, deletion creates 2 components
                    bridges.push_back({it, node});
                }
            }else{
                //already visited node
                //so check if it is a ancestor which can further reduce node's reaching time
                low[node] = min(low[node], low[it]);
            }
        }
        
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //critical connection means finding bridges

        
        //here connection means edge list, so convert to adjacency list
        vector<vector<int>> adj(n);
        for(auto e : connections){
            int u = e[0], v = e[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }

        //vis array, time of insertion and lowest insertion time
        vector<int> vis(n, 0), tin(n), low(n);

        vector<vector<int>> bridges;

        dfs(0,-1, vis, adj, tin, low, bridges);

        return bridges;
    }
};