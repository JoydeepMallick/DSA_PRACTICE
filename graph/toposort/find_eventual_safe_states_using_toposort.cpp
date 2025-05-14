class Solution {
private:
    vector<vector<int>> createGraphRev(vector<vector<int>>& adjlist){
        int V = adjlist.size();
        vector<vector<int>> adjlistrev(V);
        for(int node = 0; node < V; node++){
            for(auto adjnode : adjlist[node]){
                adjlistrev[adjnode].push_back(node);
            }
        }
        return adjlistrev;
    }

    vector<int> toposort(vector<vector<int>> &adjlistrev){
        int V = adjlistrev.size();
        vector<int> indegree(V, 0);
        for(int node = 0; node < V; node++){
            for(auto adjnode : adjlistrev[node]){
                indegree[adjnode]++;
            }
        }
        queue<int> q;
        for(int node = 0; node < V; node++){
            if(indegree[node] == 0) q.push(node);
        }

        vector<int> topoarr;
        while(!q.empty()){
            int node = q.front();q.pop();
            topoarr.push_back(node);

            for(auto adjnode : adjlistrev[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0) q.push(adjnode);
            }
        }
        return topoarr;
    }


public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adjlistrev = createGraphRev(graph);
        vector<int> safenodes = toposort(adjlistrev);
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};
