

#include <bits/stdc++.h>
using namespace std;

int maxmerit(int n, vector<vector<int>> &points){
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for(int day = 1; day < n; day++){
        vector<int> today(4,0);
        for(int last = 0; last < 4; last++){
            for(int task = 0; task < 3; task++){
                if(task != last){
                    today[last] = max(today[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = today;
    }
    return prev[3];
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
