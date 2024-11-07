#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	/*
		--
		| -- -- --  col
		|
		|
		| row
	*/	
	int col0 = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				//mark all the required
				//mark row
				matrix[i][0] = 0;
				//mark column
				if(j != 0){
					matrix[0][j] = 0; 
				}else{
					col0 = 0;
				}
			}
		}
	}

	//skip first row and col and fill the rest
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(matrix[0][j] == 0 || matrix[i][0] == 0){
				matrix[i][j] = 0;
			}
		}
	}
	//update first row now
	if(matrix[0][0] == 0){
		//all will be 0
		for(int j = 0; j < m; j++){
			matrix[0][j] = 0;
		}
	}
	//update first column
	if(col0 == 0){
		//all will be 0
		for(int i = 0; i < n; i++){
			matrix[i][0] = 0;
		}
	}
	return matrix;
}



int main(){
    vector<vector<int>> m = {{2, 4, 3}, {1, 0, 0}};
    int n = 2, m1 = 3;
    vector<vector<int>> res = zeroMatrix(m, n, m1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m1; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
