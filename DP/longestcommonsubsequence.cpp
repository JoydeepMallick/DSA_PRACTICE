#include <bits/stdc++.h>
#include <vector>
using namespace std;

int LCS(string &t1, string &t2, int ind_1, int ind_2){
    //base case
    if(ind_1 == t1.length() || ind_2 == t2.length()){
        return 0;
    }
    if(t1[ind_1] == t2[ind_2]){
        //found a match increment answer and proceed to next indices for both t1 and t2
        return (1 + LCS(t1,t2,ind_1+1, ind_2+1) );
    }
    else{
        //2 possibilities to check is current char of t1 same as next character of t2
        int pos1 = LCS(t1,t2,ind_1, ind_2+1);
        //also check if current charcter of t2 is same as next character of t1
        int pos2 = LCS(t1, t2, ind_1+1, ind_2);
        //now we need to pick the subsequence with longest length among the above
        return max(pos1, pos2);
    }
}



int LCSrecurDP(string t1, string t2, int ind_1, int ind_2,vector<vector<int>> &dp){
    //base case
    if(ind_1 == t1.length() || ind_2 == t2.length()){
        return 0;
    }

    if(dp[ind_1][ind_2] != -1) return dp[ind_1][ind_2];

    if(t1[ind_1] == t2[ind_2]){
        //found a match increment answer and proceed to next indices for both t1 and t2
        return dp[ind_1][ind_2] = (1 + LCSrecurDP(t1,t2,ind_1+1, ind_2+1, dp) );
    }
    else{
        //2 possibilities to check is current char of t1 same as next character of t2
        int pos1 = LCSrecurDP(t1,t2,ind_1, ind_2+1, dp);
        //also check if current charcter of t2 is same as next character of t1
        int pos2 = LCSrecurDP(t1, t2, ind_1+1, ind_2, dp);
        //now we need to pick the subsequence with longest length among the above
        return dp[ind_1][ind_2] = max(pos1, pos2);
    }
}

int longestCommonSubsequence(string text1, string text2) {
    //we need to consider all possible subsequences via recursion
    /* return LCS(text1, text2, 0, 0); */
    
    int n1 = text1.size(), n2 = text2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
/* return LCSrecurDP(text1,text2,0,0,dp); */
    //intialize values of dp which will act as dummies in calculation and prevent out of bounds error of indices
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    } 
    //iterative dp 
    for(int ind_1 = 1; ind_1 <= n1; ind_1++){
        for(int ind_2 = 1; ind_2 <= n2; ind_2++){
            if(text1[ind_1-1] == text2[ind_2-1]){
                dp[ind_1][ind_2] = 1 + dp[ind_1-1][ind_2-1];
            }
            else{
                int pos1 = dp[ind_1][ind_2-1];
                int pos2 = dp[ind_1-1][ind_2];
                dp[ind_1][ind_2] = max(pos1, pos2);
            }
        }
    }
    return dp[n1][n2];
}


int optmizedDP(string t1, string t2){
    int n1,n2;
    if(t1.length() < t2.length()){
        swap(t1, t2);
    }
    n1 = t1.length();//greater length for outer loops
    n2 = t2.length();//smaller length for all col in prev row
    vector<int> prevrow(n2+1, 0);//set all to 0
    for(int i = 1; i <= n1; i++){
        vector<int> currow(n2+1, 0);
        for(int j = 1; j <= n2; j++){
            if(t1[i-1] == t2[j-1]){
                currow[j] = 1 + prevrow[j-1];
            }
            else{
                currow[j] = max(currow[j-1], prevrow[j]);
            }
        }
        prevrow = currow;
    }

    return prevrow[n2];
}


int main(){
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequence("abcde", "axdcrteghg") << endl;
    cout << longestCommonSubsequence("abc", "pqrs") << endl;
    cout << longestCommonSubsequence("ezupkr", "ubmrapg") << endl;

    cout << optmizedDP("abcde", "ace") << endl;
    cout << optmizedDP("abcde", "axdcrteghg") << endl;
    cout << optmizedDP("abc", "pqrs") << endl;
    cout << optmizedDP("ezupkr", "ubmrapg")<< endl;
    return 0;
}
