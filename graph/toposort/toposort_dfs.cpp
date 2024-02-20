#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> adj[],int vis[],stack<int> &stk){
    vis[v] = 1;
    for(auto it : adj[v]){
        if(!vis[it]){
            dfs(it, adj, vis, stk);
        }
    }

    stk.push(v);
    return;
}

vector<int> toposort(int V, vector<int> adj[]){
    vector<int> lordering;
    stack<int> stk;
    int vis[V] = {0};

    for(int i = 0; i < V; i++){
        if(!vis[i]) dfs(i, adj, vis, stk);
    }

    while(!stk.empty()){
        lordering.push_back(stk.top());
        stk.pop();//dont forget to remove element
    }
    return lordering;
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
