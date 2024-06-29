class Solution {
private:
    bool compare(string s1, string s2){
        if(s1.size() != 1 + s2.size()) return false;
        bool skip_allowed = true;
        int i1 = 0, i2 = 0;
        while(i1 < s1.size()){
            if(s1[i1] == s2[i2]){
                i1++;
                i2++;
            }else{
                if(skip_allowed){ 
                    i1++;
                    skip_allowed = false;    
                }
                else return false;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [](string a, string b){
                                      return a.size() < b.size();
        });
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(compare(words[i], words[prev]) && dp[prev] + 1 > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};