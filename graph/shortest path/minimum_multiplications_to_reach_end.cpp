// problem link : https://www.naukri.com/code360/problems/minimum-operations_8360665

int minimumOperations(int n, int start, int end, vector<int> &a)
{
    const int mod = 1e3;

    int stepcnt[mod];
    fill(stepcnt, stepcnt + mod, INT_MAX);
    stepcnt[start] = 0;

    queue<pair<int,int>> q;//max priority {stepcnt, newstart}
    q.push({0, start});
    while(!q.empty()){
        auto [steps, start] = q.front();
        q.pop();

        if(start == end) return steps;

        for(auto ele : a){
            int newprod = (ele * start) % mod;
            if(steps+1 < stepcnt[newprod]){
                stepcnt[newprod] = steps+1;
                q.push({steps+1, newprod});
            }
        }
    }
    return -1;
}
