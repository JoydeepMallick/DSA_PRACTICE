#include <iostream>
#include <vector>

using namespace std;

int totalPathsobs_recur(int r, int c, vector<vector<int>> &mat){
   if(r == 0 && c == 0) return 1;
   if(r >= 0 && c >= 0 && mat[r][c] == -1) return 0;
   if(r <0 || c < 0) return 0;
   
   int left = 0, up  = 0;
   left = totalPathsobs_recur(r-1, c, mat);    
   up  = totalPathsobs_recur(r, c-1, mat);
   return left+up;
}

int callrecDP(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &dp){
   if(r==0 && c== 0) return 1;
   if((r>=0 && c>=0 && mat[r][c] == -1) || (r < 0 || c < 0)) return 0;
   if(dp[r][c] != -1) return dp[r][c];

   return dp[r][c] = callrecDP(r-1, c, mat, dp) + callrecDP(r, c-1, mat, dp);
}

int totalPathsobs_recurDP(int r, int c, vector<vector<int>> &mat){
   vector<vector<int>> dp(r+1, vector<int>(c+1, -1));
   return callrecDP(r,c,mat, dp);
}


int totalPathsobs_iterDP(int r, int c, vector<vector<int>> &mat){
   vector<vector<int>> dp(r+1, vector<int>(c+1, -1));
   for (int i = 0; i <= r; i++) {
      for (int j = 0; j <= c; j++) {
         if(i == 0 && j == 0){
            dp[i][j] = 1;
         }
         else{
            int left = 0, up = 0;
            if(mat[i][j] != -1){
               if(i > 0) up = dp[i-1][j];
               if(j > 0) left = dp[i][j-1];
            } 
            dp[i][j] = left + up; // this will result in 0 if mat[i][j] = 0 since it is blocked and can never be reached
         }
      } 
   }

   return dp[r][c];
}


int totalPathsobs_optDP(int r, int c, vector<vector<int>> &mat){
   vector<int> prevrow(c+1, -1);
   for (int i = 0; i <= r; i++) {
      vector<int> currow(c+1, -1);
      for (int j = 0; j <= c; j++) {
         if(i == 0 && j == 0){
            currow[j] = 1;
         }
         else{
            int left = 0, up = 0;
            if(mat[i][j] != -1){
               if(i > 0) up = prevrow[j];
               if(j > 0) left = currow[j-1];
            } 
            currow[j] = left + up; // this will result in 0 if mat[i][j] = 0 since it is blocked and can never be reached
         }
      }
      prevrow = currow;
   }

   return prevrow[c];
}

int main(){
    int m = 3, n =3;
    vector<vector<int>> mat = {{0,0,0},{0,-1,0}, {0,0,0}};
    cout << totalPathsobs_recur(n-1,m-1, mat) << endl;
    cout << totalPathsobs_recurDP(n-1,m-1, mat) << endl;
    cout << totalPathsobs_iterDP(n-1,m-1, mat) << endl;
    cout << totalPathsobs_optDP(n-1,m-1, mat) << endl;
    return 0;
}
