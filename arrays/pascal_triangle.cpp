#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    long long res = 1;
    for(int i = 1; i <= r; i++){
        res = res * (n-i+1);
        res = res / i;
    }
    return res;
}


void nthrow_Pascal(int n){
    long long res = 1;
    for(int i = 1; i <= n; i++){
        cout << res << " ";
        res = res * (n-i);
        res = res / i;
    }
    cout << endl;
}


vector<int> store_nthrow_Pascal(int n){
    vector<int> res;
    long long val = 1;
    for(int i = 1; i <= n; i++){
        res.push_back(val);
        val = val * (n-i);
        val = val / i;
    }
    return res;
}

vector<vector<int>> pascal_triangle(int n){
    vector<vector<int>> res;
    for(int i = 1; i <= n; i++){
        res.push_back(store_nthrow_Pascal(i));
    }
    return res;
}


int main(){
    int r = 6, c = 4;
    cout << "Pascal triangle value at row " << r << " and column " << c << " is: " << nCr(r-1, c-1) << endl;
    r = 5, c = 3;
    cout << "Pascal triangle value at row " << r << " and column " << c << " is: " << nCr(r-1, c-1) << endl;
    r = 4, c = 2;
    cout << "Pascal triangle value at row " << r << " and column " << c << " is: " << nCr(r-1, c-1) << endl;
    r = 5, c = 2;
    cout << "Pascal triangle value at row " << r << " and column " << c << " is: " << nCr(r-1, c-1) << endl;
    
    r = 5;
    cout << "The " << r << "th row of Pascal triangle is: ";
    nthrow_Pascal(r);
    
    r = 3;
    cout << "The " << r << "th row of Pascal triangle is: ";
    nthrow_Pascal(r);
    
    r = 2;
    cout << "The " << r << "th row of Pascal triangle is: ";
    nthrow_Pascal(r);
    
    r = 1;
    cout << "The " << r << "th row of Pascal triangle is: ";
    nthrow_Pascal(r);

    for(auto row : pascal_triangle(5)){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
