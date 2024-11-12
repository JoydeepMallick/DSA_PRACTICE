#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_matrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,16}};
    vector<vector<int>> ans = rotate_matrix(matrix); 
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
