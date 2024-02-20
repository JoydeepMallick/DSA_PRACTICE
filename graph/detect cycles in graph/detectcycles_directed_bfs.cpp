#include <bits/stdc++.h>
using namespace std;


bool detectcycle(int V, vector<int> adj[]){
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

    int topocount = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topocount++;// a element inserted into linear ordering

        //perform bfs traversal
        for(auto it : adj[node]){
            inorder[it]--;
            if(inorder[it] == 0) q.push(it);
        }
    }

    if(topocount == V) return false;// DAG
    else return true;// cycle does exist

}

int main(){
    vector<int> adj[] = {
        {1},
        {2},
        {3,4},
        {1},
        {},
    };
    int V = 5;
    /*
                0 -----> 1 -----> 2 ------> 4
                          ^      /
                           \    /
                            \  v 
                              3
                              
     */

    cout << "Cycle exists : " << detectcycle(V, adj) << endl;
    

    vector<int> adj2[] = {
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2},
    };
    V = 6;
    /*
                5-----> 0 <------4
                |                |
                |                |
                V                V
                2-----> 3 ------>1
     */

    cout << "Cycle exists : " << detectcycle(V, adj2) << endl;
    return 0;
}
