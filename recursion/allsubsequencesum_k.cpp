#include <iostream>
#include <vector>
using namespace std;

void printsub(int ind, vector<int> &sub,int s, int k, int arr[], int n){
    if(ind == n){
        if(s == k){
            cout << "[ ";
            for(auto it : sub){
                cout << it << ",";
            }
            cout << "\b ]\n";
        }
        return;
    }

    //take the element at ind in the subsequence 
    sub.push_back(arr[ind]);
    s += arr[ind];
    printsub(ind+1, sub,s,k, arr, n);
    // do not take the element at ind in the subsequence 
    sub.pop_back();
    s -= arr[ind];
    printsub(ind+1, sub,s,k, arr, n);
 
}

int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    vector<int> sub;
    int s = 0;
    printsub(0, sub,s,k, arr, n);
    return 0;
}
