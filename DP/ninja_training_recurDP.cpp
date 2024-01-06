#include <bits/stdc++.h>
using namespace std;
    
int recurDP(int day, vector<vector<int>> &points, int lasttask, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        //found the maximum of remaining tasks which weren't performed earlier
        for(int i = 0; i < 3; i++){
            if(i != lasttask){
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[0][lasttask] = maxi;
    }

    if(dp[day][lasttask] != -1){
        return dp[day][lasttask];
    }

    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != lasttask){
            int merit = points[day][i] + recurDP(day-1, points, i, dp);
            maxi = max(maxi, merit);
        }
    }

    return dp[day][lasttask] = maxi;
}

int maxmerit(int n, vector<vector<int>> &points){
    //task 0, 1, 2  and 3 is no task 
    vector<vector<int>> dp(n, vector<int>(4, -1));
    //dp[day][task] means the maximum merit till day provided task was done on day+1 
    return recurDP(n-1, points, 3, dp);
}

int main(){
    int noofdays = 4;
    vector<vector<int>> merits = {
        {2,1,3},
        {3,4,6},
        {10,1,6},
        {8,3,7}
    };//ans = 25 

    cout << maxmerit(noofdays, merits) << endl;
    return 0;
}
