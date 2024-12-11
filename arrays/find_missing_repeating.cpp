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
//optimal 2 
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    
    int n = a.size();
    int xorval = 0;
    for(int i = 0; i < n; i++){
        xorval = xorval^ a[i];
        xorval = xorval^ (i+1);
    }
    int bitind = 0;
    while((xorval & (1 << bitind)) == 0){
        bitind++;
    }

    int team0 = 0, team1 = 0;
    //first operate with array
    for(int i = 0; i < n; i++){
        if((a[i] & (1 << bitind)) != 0){
            team1  = team1^ a[i];
        }else{
            team0  = team0^ a[i];
        }
    }
    //then operate with 1 till N
    for(int i = 1; i < n+1; i++){
        if((i & (1 << bitind)) != 0){
            team1  = team1^ i;
        }else{
            team0  = team0^ i;
        }
    }
    int repeat, miss;
    if(find(a.begin(), a.end(), team0) != a.end()){
        repeat = team0;
        miss = team1;
    }else{
        repeat = team1;
        miss = team0;
    }
    return {repeat, miss};

}

// optimal 2 more logic
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    
    int n = a.size();
    int xorval = 0;
    for(int i = 0; i < n; i++){
        xorval = xorval^ a[i];
        xorval = xorval^ (i+1);
    }
    int bitval = xorval & ~(xorval-1);

    int team0 = 0, team1 = 0;
    //first operate with array
    for(int i = 0; i < n; i++){
        if((a[i] & bitval) != 0){
            team1  = team1^ a[i];
        }else{
            team0  = team0^ a[i];
        }
    }
    //then operate with 1 till N
    for(int i = 1; i < n+1; i++){
        if((i & bitval) != 0){
            team1  = team1^ i;
        }else{
            team0  = team0^ i;
        }
    }
    int repeat, miss;
    if(find(a.begin(), a.end(), team0) != a.end()){
        repeat = team0;
        miss = team1;
    }else{
        repeat = team1;
        miss = team0;
    }
    return {repeat, miss};

}

