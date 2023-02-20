#include<bits/stdc++.h>
using namespace std;

//for more methods simply read the below document
//https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/
void printvis(vector<bool> vis){
    cout << "\n{";
    for(int i : vis) cout << i <<" ";
    cout << "}\t";
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis){
    vis[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();//total rows
    int m = grid[0].size();//total columns 

    while (!q.empty()){
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();//pop front from queue
                //traverse all neighbours in all eight directions and mark them as visited if possible and valid
        for(int delrow = -1; delrow <= 1; delrow++){
            for(int delcol = -1; delcol <= 1; delcol++){
                int nb_row = cur_row + delrow;
                int nb_col = cur_col + delcol;
                if(
                        0 <= nb_row && nb_row < n  &&
                        0 <= nb_col && nb_col < m &&
                        grid[nb_row][nb_col] == 1 && //has to be land 
                        !vis[nb_row][nb_col]//no visited already
                  ){
                    //mark as visited
                    vis[nb_row][nb_col] = 1;
                    //add it to the queue for further bfs
                    q.push({nb_row, nb_col});
                }
            }
        }
    }
}


int countIsland(vector<vector<int>> &grid){
    int n =  grid.size();
    int m = grid[0].size();
    //create visited array of all nodes
    vector<vector<bool>> vis(n, vector<bool>(m,0));
    int cnt = 0;
    for(int row =0; row < n; row++){
        for (int col = 0; col < m; col++) {
            if(!vis[row][col] && grid[row][col] == 1){ //if not visited and is a land then only perform dfs
                cnt++;
                dfs(row, col, grid, vis);
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,1,0},
        {0,0,0,1,0},
    };

    /*
     *          ie. total 4 islands 
     */
    cout << "\n\nNumber of islands : " << countIsland(grid) << endl;
    return 0;
}
