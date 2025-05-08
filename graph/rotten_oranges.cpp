#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> updated_data){
    for(auto row : updated_data){
        for(int cell : row) cout << cell << " ";
        cout << "\n";
    }
}


int orangesRotting(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    // visited matrix to keep track of the visited cell.
    int vis[n][m];//will be filled with either 0 or 2
    // queue stores rowIndex,colIndex and time taken to rot respectively.
    queue<pair<pair<int, int>, int> > q;
 
    // counter to keep track of fresh cells.
    int cntfresh = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                //if orange visited is already rotten.
                q.push({{i,j}, 0});
                vis[i][j] = 2;//visited cell marked as rotten 
            }
        
            else{
                vis[i][j] = 0; //mark as unvisited to be updated later
            }

            if(grid[i][j] == 1) cntfresh++;
        }
    }

    int cnt = 0, tmin = 0;
    int delrow[] = { -1, 0, +1, 0 };
    int delcol[] = { 0, +1, 0, -1 };
    
    while(!q.empty()){
        int cur_row = q.front().first.first; // row index
        int cur_col = q.front().first.second; // col index
        int t = q.front().second; // time an orange at a cell takes to rot.
        q.pop();
        tmin = max(tmin, t);

        for(int i = 0; i < 4; i++){
            int nb_row = cur_row + delrow[i];
            int nb_col = cur_col + delcol[i];
            if(
                    0 <= nb_row && nb_row < n &&
                    0 <= nb_col && nb_col < m &&
                    grid[nb_row][nb_col] == 1 && // if current location has a fresh orange 
                    vis[nb_row][nb_col] != 2 // if the location is not already visited, i.e. its not already rotten
              ){
                q.push({{nb_row, nb_col}, t+1});
                //mark as visited and rotted just now 
                vis[nb_row][nb_col] = 2;
                cnt++;
            }
        }
    }
    cout << "\nfinal visited array :-\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << vis[i][j] << " ";
        cout << "\n";
    }
    return (cnt == cntfresh) ? tmin : -1;
}

int main(){
    /*
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
     */
    vector<vector<int>> data = {
            {2, 1, 0, 2, 1}, 
            {0, 0, 1, 2, 1}, 
            {1, 0, 0, 2, 1}    
    };
    cout << "Initially data entered :-\n\n";
    print(data);
    int ans = orangesRotting(data);
    if(ans == -1) cout << "All oranges could not be rotted\n\n";
    else cout << "Total time taken to rot all oranges : -  " << ans << endl;
    return 0;
}


// a different approach to reduce space and time by a bit
class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            //bfs implementation
            queue<pair<int, int>> q;
            //insert all rotten orange locations with 0 time infection
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> vis(m, vector<int>(n, 0));
            int cntfreshoranges = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 2) {
                        q.push({i,j});
                        vis[i][j] = 2;//mark visited cells
                    }else if(grid[i][j] == 1){
                        cntfreshoranges++; 
                    }
                }
            }
    
            //bfs with increasing time
            int maxtime = -1;//since we need the answer of 0 if no orange can be rotten except for already rotten ones, helps ease calculations
            while(!q.empty()){
                int qsize = q.size();
                while(qsize--){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    int dx[] = {0,1,0,-1};
                    int dy[] = {1,0,-1,0};
                    for(int i = 0; i < 4; i++){
                        int newx = x + dx[i], newy = y + dy[i];
                        if(newx >= 0 && newx < m && newy >= 0 && newy < n 
                        && grid[newx][newy] == 1 && !vis[newx][newy]){
                            //rot the new orange and increase time
                            vis[newx][newy] = 2;
                            cntfreshoranges--;//1 fresh orange was rotten
                            q.push({newx, newy});
                        }
                    }
                }
                maxtime++;
            }
            //check if any fresh orange was unrotten
            if(cntfreshoranges > 0) return -1;
            if(maxtime == -1) return 0;// nothing rotten found
            return maxtime;
        }
    };