#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int vis[], int pathvis[], vector<int> edgelist[]){

    vis[v] = true;
    pathvis[v] = true;

    for(auto ver : edgelist[v]){
        //if not visited node
        if(!vis[ver]){
            if(dfs(ver, vis, pathvis, edgelist) == true) return true;
        }
        //if already visited node, check if path  visited
        else if(vis[ver] && pathvis[ver]) return true;//cycle detected if vertex revisited on same path
    }

    //when we end a dfs we need to return back hence make pathvis of current vertex 0
    pathvis[v] = 0;
    return false;
}

bool detectcycles(int V, vector<int> edgelist[] ){
    int vis[V+1] = {0};
    int pathvis[V+1] = {0};

    for(int v = 1; v <= V; v++){
        if(!vis[v]){
            if(dfs(v, vis, pathvis, edgelist) == true) return true;//a cycle found
        }
    }

    return false;
}


int main(){

    /*

        1-----> 2 -------> 3 -------> 4
                           |          |
                           |          |
                           |          |
                           |          |
                           v          v 
                           7--------->5-------> 6
     
                           contains no cycle 
     */

    vector<int> edgelist[] = {
        {},//1 based indexing 
        {2},
        {3},
        {4,7},
        {5},
        {6},
        {},
        {5},
    };
    int V = 7;

    cout << "Directed graph 1 contains cycles : " << detectcycles(V,edgelist) << endl;
    
    /*

         1-----> 2 -------> 3 -------> 4
                ^           |          |
                |           |          |
                8           |          |
               / ^          |          |
              /   \         v          v 
             v     \        7--------->5-------> 6
            9------>10
                         
            contains a cycle 
     */

    vector<int> edgelist2[] = {
        {},//1 based indexing 
        {2},
        {3},
        {4,7},
        {5},
        {6},
        {},
        {5},
        {2,9},
        {10},
        {8},
    };
    V = 10;

    cout << "Directed graph 2 contains cycles : " << detectcycles(V,edgelist2) << endl;

    return 0;
}
