
#include <bits/stdc++.h>
using namespace std;

int maxmerit(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, 0));

    //base cases
    dp[0][0] =  max(points[0][1], points[0][2]);
    dp[0][1] =  max(points[0][0], points[0][2]);
    dp[0][2] =  max(points[0][1], points[0][0]);
    dp[0][3] =  max(points[0][1], max(points[0][0], points[0][2]));

    for (int day = 1; day < n; day++) {
       for (int last = 0; last < 4; last++) {
           //now from list of available task for a given last task choose the maximum from remaining task 
           dp[day][last] = 0;
            
            for (int task = 0; task < 3; task++) {
                if(task != last){
                    int maxpointsforday = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], maxpointsforday);
                }
            }
       } 
    }
    return dp[n-1][3];
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
