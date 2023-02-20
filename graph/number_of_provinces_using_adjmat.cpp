
#include<bits/stdc++.h>
using namespace std;

void printvis(vector<bool> vis){
    cout << "\n{";
    for(int i : vis) cout << i <<" ";
    cout << "}\t";
}

void dfs(int startnode, vector<vector<int>> &adjmat, vector<bool> &vis){
    //this basically fills up visited array and helps in counting number of provinces
    vis[startnode] = 1;
    for(int j = 0; j < (int)adjmat.size(); j++){
        if (startnode != j && adjmat[startnode][j] && !vis[j]) {
                dfs(j, adjmat, vis);
            } 
    }
}


int countProvinces(vector<vector<int>> adjmat, int V){
    if(adjmat.empty()) return 0;

    //create a visited array to track the nodes have been visited
    vector<bool> vis(V, 0);
    //store the number of provinces
    int cnt = 0;
    for(int i = 0; i < V; i++){
        cnt += !vis[i] ? dfs(i,adjmat, vis), 1 : 0;
        printvis(vis);
        cout << "count -> " << cnt << endl;
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
