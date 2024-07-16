//memoization
class Solution {
private:
    int f(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mincost = INT_MAX;
        for(int ind = i; ind <= j; ind++){
            int cost = (cuts[j+1] - cuts[i-1]) //cost of current cut
            + f(cuts, i, ind-1, dp) // left portion of current piece 
            + f(cuts, ind+1, j, dp);//right portion of current piece
        
            mincost = min(mincost, cost);
        }
        return dp[i][j] = mincost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        //n is the size of stick not size of cuts
        int sz_cuts = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        //cuts now [0, cuts[0], cuts[1],......, last element of cuts, n]
        //cuts need to be sorted
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(sz_cuts+1, vector<int>(sz_cuts+1, -1));
        return f(cuts, 1, sz_cuts, dp);//interested in cuts provided actually and cuts was updated so be careful with indices
    }
};

//tabulation

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        //n is the size of stick not size of cuts
        int sz_cuts = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        //cuts now [0, cuts[0], cuts[1],......, last element of cuts, n]
        //cuts need to be sorted
        sort(cuts.begin(), cuts.end());
        //initialize all 0 to cover base case
        vector<vector<int>> dp(sz_cuts+2, vector<int>(sz_cuts+2, 0));
        for(int i = sz_cuts; i >= 1; i--){
            for(int j = i; j <= sz_cuts; j++){
                int mincost = INT_MAX;
                for(int ind = i; ind <= j; ind++){
                    int cost = (cuts[j+1] - cuts[i-1]) //cost of current cut
                    + dp[i][ind-1] // left portion of current piece 
                    + dp[ind+1][j];//right portion of current piece
                
                    mincost = min(mincost, cost);
                }
                dp[i][j] = mincost;
            }
        }

        return dp[1][sz_cuts];//interested in cuts provided actually and cuts was updated so be careful with indices
    }
};