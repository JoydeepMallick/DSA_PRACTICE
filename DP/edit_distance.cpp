// recursive DP
class Solution {
private:
    int f(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return  dp[i][j] = 0 + f(s1, s2 ,i-1, j-1,dp);
        }
        else{
            return dp[i][j] = 1 + min({
                f(s1,s2, i-1, j, dp), // delete current
                f(s1,s2, i, j-1, dp), // insert after
                f(s1,s2, i-1, j-1, dp) // replace current
            });
        }
    }
public:
    int minDistance(string word1, string word2) {
        int  len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1, vector<int> (len2, -1));
        return f(word1, word2, len1-1, len2-1, dp);
    }
};


// tabulated DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        int  len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int> (len2+1, -1));
        for(int i = 0; i <= len1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= len2; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    });
                }
            }
        }
        return dp[len1][len2];
    }
};

//space optimized DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        int  len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int> (len2+1, -1));
        for(int i = 0; i <= len1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= len2; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    });
                }
            }
        }
        return dp[len1][len2];
    }
};