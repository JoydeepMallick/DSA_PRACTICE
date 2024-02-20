
#include <bits/stdc++.h>
using namespace std;


vector<int> toposort(int V, vector<int> adj[]){
    //calculate the inorder of the graph
    int inorder[V] = {0};
    for(int i = 0; i < V; i++){
        for(auto node : adj[i]){
            inorder[node]++;
        }
    }

    // we need a queue data structure to perform modified bfs 
    queue<int> q;
    //now put the nodes with indegree 0 in queue as starting point 
    for(int i = 0; i < V; i++){
        if(inorder[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);// inserted in linear ordering 

        //perform bfs traversal
        for(auto it : adj[node]){
            inorder[it]--;
            if(inorder[it] == 0) q.push(it);
        }
    }

    return topo;

}

int main(){
    vector<int> adj[] = {
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2},
    };
    int V = 6;
    /*
                5-----> 0 <------4
                |                |
                |                |
                V                V
                2-----> 3 ------>1
     */

    cout << "One of valid linear ordering for toposort : ";
    for(auto ele : toposort(V, adj)){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
