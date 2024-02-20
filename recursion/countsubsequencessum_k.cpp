#include <iostream>
#include <vector>
using namespace std;

int printsub(int ind, vector<int> &sub,int s, int k, int arr[], int n){
    if(ind == n){
        if(s == k){
            return 1;
        }
        else{
            return 0;
        }
    }

    //take the element at ind in the subsequence 
    sub.push_back(arr[ind]);
    s += arr[ind];
    int l = printsub(ind+1, sub,s,k, arr, n);
    // do not take the element at ind in the subsequence 
    sub.pop_back();
    s -= arr[ind];
    int r = printsub(ind+1, sub,s,k, arr, n);
 
    return l+r;
}

int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    vector<int> sub;
    int s = 0;
    cout << "Possible subsequence count : " << printsub(0, sub,s,k, arr, n) << endl;
    return 0;
}
