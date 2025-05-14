class Solution {

private:
    vector<vector<int>> createGraph(int V, vector<vector<int>> &edges){
        vector<vector<int>> adjlist(V);
        for(auto it : edges){
            adjlist[it[1]].push_back(it[0]);
        }
        return  adjlist;
    }

    bool isDAG(int V, vector<vector<int>> &edges){
        vector<vector<int>> adjlist = createGraph(V, edges);
        vector<int> indegree(V, 0);
        for(int node = 0; node < V; node++){
            for(auto adjnode : adjlist[node]){
                indegree[adjnode]++;
            }
        }

        int topocnt = 0;
        queue<int> q;
        for(int node = 0; node < V; node++){
            if(indegree[node] == 0) q.push(node);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topocnt++;
            for(auto adjnode : adjlist[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0) q.push(adjnode);
            }
        }
        if(topocnt == V) return true;//DAG
        else return false;//not DAG contains cycle
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      //if there is some cyclic dependency there will be a set of subjects in cycle which can never be studied since to start one we need another causing a deadlock situation
        return isDAG(numCourses, prerequisites);
    }
};
