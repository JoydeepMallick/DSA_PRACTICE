#include<vector>
#include<iostream>
using namespace std;

//optimal using sum diff
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int  n = a.size();
    long long Sn = n*(n+1ll)/2, Sn2 = n*(n+1ll)*(2ll*n+1ll)/6;
    long long S = 0, S2 = 0;
    for(int i = 0; i < n; i++){
        S += a[i];
        S2 += (long long)a[i]*(long long)a[i];
    }
    long long val1 = S - Sn;
    long long val2 = (S2 - Sn2)/val1;

    long long repeat = (val1 + val2)/2;
    long long miss = repeat - val1;
    return {(int)repeat, (int)miss};
}

//optimal using XOR