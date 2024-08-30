#include <bits/stdc++.h>
using namespace std;

int secondlargest(vector<int> &a, int n){
    int lar = a[0];
    int seclar = INT_MIN;
    for(int i = 1; i < n; i++){
        if(a[i] > lar){
            seclar = lar;
            lar = a[i];
        }else if(a[i] > seclar && a[i] < lar){
            seclar = a[i];
        }
    }
    return seclar;
}

int secondsmallest(vector<int> &a, int n){
    int small = a[0];
    int secsmall = INT_MAX;
    for(int  i = 1; i < n; i++){
        if(a[i] < small){
            secsmall = small;
            small = a[i];
        }
        else if(a[i] < secsmall && a[i] > small){
            secsmall = a[i];
        }
    }
    return secsmall;
}

int main(){
    vector<int> a = {2, 4, 5, 12, 9, 67, 9, 1, 39, 55, 54};
    int n = 11;
    int secondlar = secondlargest(a, n);
    int secondsmall = secondsmallest(a, n);
    cout << secondlar << " " << secondsmall << "\n\n\n";
    return 0;
}


 
