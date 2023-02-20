#include<bits/stdc++.h>
using namespace std;

void dfs(int startnode, vector<int> adjlst[], int vis[]){
    //this basically fills up visited array and helps in counting number of provinces
    vis[startnode] = 1;
    for(int it : adjlst[startnode]){
        if(!vis[it]) dfs(it, adjlst, vis);
    }
}


int countProvinces(vector<vector<int>> adjmat, int V){
    //convert matrix to adjacency list
    vector<int> adjlst[V];
    for(int i = 0; i < V; i++){
        for (int j = 0; j < V; j++) {
            if(adjmat[i][j] && i!=j){
                //avoid self loops
                adjlst[i].push_back(j);
                adjlst[j].push_back(i);
            }
        }
    }
    //create a visited array to track the nodes have been visited
    int vis[V] = {0};
    //store the number of provinces
    int cnt = 0;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjlst, vis);
        }
    }

    return cnt;
}

int main(){
    vector<vector<int>> adjmat = {
        {0,1,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,1,0,1,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,1,0},
        };

    /*
     *     1--2    4--5    7
     *         \       \    \
     *          3      6     8   
     *
     *          ie. total 3 provinces
     */
    //V denotes no. of vertices from 0 to n-1(even though naming is 1 till n its doesn't matter in our workflow).
    int V = 8;
    cout << "\n\nNumber of provinces : " << countProvinces(adjmat, V) << endl;
    return 0;
}
