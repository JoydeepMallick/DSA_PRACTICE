// memoization
class Solution {
private:
    int f(string &s ,string &t , int i, int j, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
     
        if(s[i] == t[j]) {
            return dp[i][j] = f(s,t,i-1, j-1, dp) + f(s,t, i-1, j, dp);
        } 
        else{
            return dp[i][j] = f(s,t, i-1, j, dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return f(s,t, s.size()-1, t.size()-1, dp);
    }
};


//iterative DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        vector<vector<double>> dp(slen+1, vector<double>(tlen+1, -1));
        
        for(int i = 0; i <= slen; i++){
            dp[i][0] = 1;//when t is empty
        }
        for(int j = 1; j <= tlen; j++){
            dp[0][j] = 0; //when s is empty but t is not
        }

        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= tlen; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return int(dp[slen][tlen]);
    }
};

//space optimized dp
class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        vector<double> cur(tlen+1, 0), prev(tlen+1, 0) ;
        prev[0] = cur[0] = 1;
        
        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= tlen; j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = prev[j-1] + prev[j];
                }else{
                    cur[j] = prev[j];
                }
            }
            prev = cur;
        }
        return int(prev[tlen]);
    }
};

//one 1D array DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        vector<double> dp(tlen+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= slen; i++){
            for(int j = tlen; j >= 1; j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }
        return int(dp[tlen]);
    }
};