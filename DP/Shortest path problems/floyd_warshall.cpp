#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> mat){
    
    for(auto it : mat){
        cout << "\n|";
        for(auto it2 : it) printf("%3d ",it2);
        cout << "|";
    }
    cout << endl;
}

vector<vector<int>> listtomatrix(int V, vector<vector<int>> edgelist){
    vector<vector<int>> adjmatrix(V, vector<int> (V, -1));//fill all with -1 
    for(auto it : edgelist){
        int u = it[0]-1, v = it[1]-1, wt = it[2];//maintain 0 based indexing
        adjmatrix[u][v] = wt;
        adjmatrix[u][u] = 0;
        adjmatrix[v][v] = 0;
    }
    return adjmatrix;
}

void floyd_warshall(vector<vector<int>> &adjmatrix){
    //inplace updation
    int V = adjmatrix.size();
    for( int i = 0; i < V; i++ ){
        for(int j = 0; j < V; j++){
            if(adjmatrix[i][j] == -1){
                adjmatrix[i][j] = 1e9;
            }
        }
    }

//actual implementation 
    for(int k = 0; k < V; k++){
        for( int i = 0; i < V; i++ ){
            for(int j = 0; j < V; j++){
                adjmatrix[i][j] = min( adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j] );
            }
        }
        cout << "After iteration " << (k+1) << " :";
        printMatrix(adjmatrix);
    }

    //check for negative cycle , if any diagonal element contains negative value
    for(int i =  0; i < V; i++) if(adjmatrix[i][i] < 0) cout << " NEgative cycle exists!!!\n";

    //replace intmax by -1 as it was initially 
    for( int i = 0; i < V; i++ ){
        for(int j = 0; j < V; j++){
            if(adjmatrix[i][j] == 1e9){// dont set intmax else when something added to it it will cause range to exceed causing inappropriate result
                adjmatrix[i][j] = -1;
            }
        }
    }

}

int main(){
    int V = 4;
    vector<vector<int>> edgelist = {
        {1, 2, 3},
        {1, 4, 7},
        {2, 1, 8},
        {2, 3, 2},
        {3, 1, 5},
        {3, 4, 1},
        {4, 1, 2},
    };
    vector<vector<int>> adjmatrix = listtomatrix(V, edgelist);
    cout << "Entered adjacency matrix : ";
    printMatrix(adjmatrix);

    floyd_warshall(adjmatrix);
    cout << "All pair shortest path post operation :";
    printMatrix(adjmatrix);
}
