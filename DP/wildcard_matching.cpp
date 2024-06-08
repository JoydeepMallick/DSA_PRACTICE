//memoization
class Solution {
private:
    bool f(string &s, string &p, int is, int ip, vector<vector<int>> &dp){
        if(ip < 0){
            if(is < 0) return true;
            else return false;// if pattern end string must end else no match
        }
        if(ip >= 0 && is < 0) {
            //if string ends rest all in pattern must be *
            for(int i = 0; i <= ip; i++){
                if(p[i] != '*') return false;
            }
            return true;
        }
        if(dp[is][ip] != -1) return dp[is][ip];

        if(s[is] == p[ip] || p[ip] == '?'){
            return dp[is][ip] = f(s,p, is-1, ip-1, dp);
        }else if(p[ip] == '*'){
            //pick 
            bool pick = f(s,p, is-1,ip, dp);
            //not pick and compare
            bool notpick = f(s,p, is, ip-1, dp);
            return  dp[is][ip] = pick || notpick;
        }
        //no match found
        return false;
        
    }

public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        vector<vector<int>> dp(lens, vector<int>(lenp, -1));

        return f(s,p, lens-1, lenp-1, dp);
    }
};


//tabulation
class Solution {

public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
        dp[0][0] = true; // both empty
        for(int is = 1; is <= slen; is++ ){//when pattern empty but string is not
            dp[is][0] = false;
        }
        //when string is empty but pattern is not, see the index from 1 till how much * exist as they are valid
        for(int ip = 1; ip <= plen; ip++ ){
            bool ans = true;
            for(int jp = 1; jp <= ip; jp++){
                if(p[jp-1] != '*'){
                    ans = false;
                    break;
                }
            }
            dp[0][ip] = ans;
        }

        for(int is = 1; is <= slen; is++){
            for(int ip = 1; ip <= plen; ip++){
                if(s[is-1] == p[ip-1] || p[ip-1] == '?'){
                    dp[is][ip] = dp[is-1][ ip-1];
                }else if(p[ip-1] == '*'){
                    //pick 
                    bool pick = dp[is-1][ip];
                    //not pick and compare
                    bool notpick = dp[is][ip-1];
                    dp[is][ip] = pick || notpick;
                }
                //no match found
                else{
                    dp[is][ip] = false;
                }
            }
        }

        return dp[slen][plen];
    }
};

//space optimization
class Solution {

public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<bool> prev(plen+1, false), cur(plen+1, false);
        prev[0] = true; // both empty
        
        //when string is empty but pattern is not, see the index from 1 till how much * exist as they are valid
        for(int ip = 1; ip <= plen; ip++ ){
            bool ans = true;
            for(int jp = 1; jp <= ip; jp++){
                if(p[jp-1] != '*'){
                    ans = false;
                    break;
                }
            }
            prev[ip] = ans;
        }

        for(int is = 1; is <= slen; is++){
            cur[0] = false;//when pattern empty but string is not
            for(int ip = 1; ip <= plen; ip++){
                if(s[is-1] == p[ip-1] || p[ip-1] == '?'){
                    cur[ip] = prev[ ip-1];
                }else if(p[ip-1] == '*'){
                    //pick 
                    bool pick = prev[ip];
                    //not pick and compare
                    bool notpick = cur[ip-1];
                    cur[ip] = pick || notpick;
                }
                //no match found
                else{
                    cur[ip] = false;
                }
            }
            prev = cur;
        }

        return prev[plen];
    }
};
