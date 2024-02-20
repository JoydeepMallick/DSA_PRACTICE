
#include <bits/stdc++.h>
using namespace std;

vector<int> safeStates(int V, vector<int> adj[]){
    //reverse edges of graph to form a new graph
    vector<int> adjRev[V];
    int indegree[V] = {0}; //for reversed graph 
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    //figure out the terminal nodes intially 
    for(int i = 0 ; i < V; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> safeNodes;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for(auto it : adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }


    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}


int main(){
    /*
     o based indexing 

     0 ------> 1 ------> 2 --------> 3 --------> 5
               ^                     |           |
               |                     |           |
               |                     |           |
               8                     4 --------> 6 ---------> 7
              / \ 
             /   \
            v     v 
            9 --> 10
            ^
            |
            |
            11 

            safe nodes = 0,1,2,3,4,5,6,7

*/
    int V = 12;

    vector<int> adj[] = {
        {1},
        {2},
        {3},
        {4,5},
        {6},
        {6},
        {7},
        {},
        {1,9},
        {10},
        {8},
        {9},
    };
    
    cout << "Safe states : ";
    for(auto ele : safeStates(V, adj)){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
