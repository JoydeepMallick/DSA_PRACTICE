#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int locx, int locy, int iniColor, int newColor, int delrow[], int delcol[]){
    ans[locx][locy] = newColor;//set the current location with new color
    int n = image.size();
    int m = image[0].size();
    for(int i = 0; i < 4; i++){
        int nb_row = locx + delrow[i];
        int nb_col = locy + delcol[i];
        if(
                0<=nb_row && nb_row < n &&
                0<=nb_col && nb_col < m &&
                image[nb_row][nb_col] == iniColor && // current location must have inital color indicating its connected
                ans[nb_row][nb_col] != newColor //this means that whether the current location we want to color has already be colored earlier hence ans acts as visited node
          ){
            dfs(image, ans, nb_row, nb_col, iniColor, newColor, delrow, delcol);
        }
    }
}

vector<vector<int>> floodfill(vector<vector<int>> &image, int locx, int locy, int newColor){
    vector<vector<int>> ans = image;
    int iniColor = image[locx][locy];

    if(iniColor == newColor){
        //same color to apply at the exact same location hence no change
        return image;
    }
    /*
     * we can mmove in 4 directions only i.e top below right elft  
     *hence four possible locations to traverse in traversal.

     (locx+1, locy), (locx-1, locy)

     (locx, locy+1), (locx, locy-1)

*/
    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, +1, 0, -1};
    dfs(image, ans, locx, locy, iniColor, newColor, delrow, delcol );
    return ans;
}

void print(vector<vector<int>> updated_data){
    for(auto row : updated_data){
        for(int cell : row) cout << cell << " ";
        cout << "\n";
    }
}

int main(){
    int locx, locy, newcolor;
    vector<vector<int>> data = {
        { 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 0, 0, 1, 1, 0, 1, 1 },
        { 1, 2, 2, 2, 2, 0, 1, 0 },
        { 1, 1, 1, 2, 2, 0, 1, 0 },
        { 1, 1, 1, 2, 2, 2, 2, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 1 },
        { 1, 1, 1, 1, 1, 2, 2, 1 },
    };
    locx = 4, locy = 4, newcolor = 3;
    cout << "Initially data entered :-\n\n";
    print(data);
    vector<vector<int>> updated_data = floodfill(data, locx, locy, newcolor);
    cout << "\nAfter Flood Fill Algorithm was executed (assume current coorinates to start as (4,4) and newcolor to be 3):-\n\n";
    print(updated_data);
    return 0;
}
