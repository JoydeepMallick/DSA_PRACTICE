class Solution {
private:
    bool cyclecheckdfs(vector<vector<int>> &adjlist, vector<int>& vis, vector<int>& pathvis, vector<int>& isSafe, int curnode){
        vis[curnode] = 1;
        pathvis[curnode] = 1;

        for(auto adjnode : adjlist[curnode]){
            if(!vis[adjnode]){
                if(cyclecheckdfs(adjlist, vis, pathvis, isSafe, adjnode) == true){//one of the adjacent nodes of curnode leads to a cycle
                    isSafe[curnode] = 0;
                    return true;
                }
            }else if(pathvis[adjnode]){//both vis and pathvis hence cycle found
                isSafe[curnode] = 0;
                return true;
            }
        }
        pathvis[curnode] = 0;
        //all checks done for current, if it reaches here means no cycle was found
        isSafe[curnode] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //a node which is part of a cycle can never have fixed ending point hence never land at a safe node and not a safe node.
        // a node which leads to a cycle cannot be safe

        //hence all paths must be traversed and checked per node to justify all lead to safe node.

        //we are sure sink nodes, ie. outdegree 0 is safe, our base case
        int V = graph.size();
        vector<int> vis(V, 0), pathvis(V, 0), isSafe(V, 0);
        //check all disconnected components
        for(int node = 0; node < V; node++){
            cyclecheckdfs(graph, vis, pathvis, isSafe, node);//we need to check for all nodes regardless as all cycles needs detection
        }   
        
        vector<int> safeNodes;
        for(int i = 0; i < V; i++){
            if(isSafe[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
