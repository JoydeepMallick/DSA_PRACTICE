#include <bits/stdc++.h>
using namespace std;

void print(vector<int> edgelist[], int n){
    for(int i =  1; i <= n; i++){
        cout << i << " -> { ";
        for(auto it : edgelist[i]){
            cout << it << ", ";
        }
        cout << "\b\b }\n";
    }
}

bool check(int start, int V, vector<int> adj[], int color[]){
    queue<int> q;
    q.push(start);
    color[start] = 0;//assume intial color to be 0
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //color all adjacent nodes in bfs fashion
        for(auto it :   adj[node]){
            if(color[it] == -1){
                //not yet colored 
                color[it] = !color[node];
                q.push(it);//push this node to perform bfs on it 
            }
            else if(color[it] == color[node]){
                //same color as parent node
                return false;
            }
        }
    }
    return true; // the entire graph or the entire connected compoent is Bipartite 
}

//helps check all components if some are disconnected 
bool isBipartite(int V, vector<int> edgelist[]){
    int color[V+1];
    for(int i = 1; i <= V; i++) color[i] = -1;
    for(int i = 1; i <= V; i++){
        if(color[i] == -1){
            //not yet colored 
            if(check(i, V, edgelist, color) == false){
                return false; 
            }
        }
    }
    return true;
}

int main(){
    vector<int> edgelist[] = {
        {},//1 based indexing so 0 is kept blank
        {2},
        {1,3,6},
        {2,4},
        {3,5,7},
        {4,6},
        {2,5},
        {4,8},
        {7},
    };
    
    int V = 8;
    cout << "Given edgelist :- \n";
    print(edgelist, V);
    cout << "\n\nBipartite graph : " << isBipartite(V, edgelist) <<endl;
    return 0;
}
