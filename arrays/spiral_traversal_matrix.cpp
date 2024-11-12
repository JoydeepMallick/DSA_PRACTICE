#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    vector<int> ans;
    int top = 0, bottom = MATRIX.size()-1;
    int left = 0, right = MATRIX[0].size()-1;
    while(top <= bottom && left <= right){
        //left
        for(int c = left; c <= right; c++){
            ans.push_back(MATRIX[top][c]);
        }
        top++;

        //down
        for(int r = top; r <= bottom; r++){
            ans.push_back(MATRIX[r][right]);
        }
        right--;

        //NOTE : Top and Right are already updated which needs to be checked again in current iteration below since the last check within while is no valid
        //left
        if(top <= bottom){
            for (int c = right; c >= left; c--) {
              ans.push_back(MATRIX[bottom][c]);
            }
            bottom--;
        }

        //up
        if(left <= right){
            for (int r = bottom; r >= top; r--) {
              ans.push_back(MATRIX[r][left]);
            }
            left++;
        }
    } 
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,16}};
    vector<int> ans = spiralMatrix(matrix);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
