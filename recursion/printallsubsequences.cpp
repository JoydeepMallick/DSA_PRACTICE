#include <iostream>
#include <vector>
using namespace std;

void printsub(int ind, vector<int> &sub, int arr[], int n){
    if(ind == n){
        cout << "[ ";
        for(auto it : sub){
            cout << it << ",";
        }
        cout << "\b ]\n";
        return;
    }

    //take the element at ind in the subsequence 
    sub.push_back(arr[ind]);
    printsub(ind+1, sub, arr, n);
    
    // do not take the element at ind in the subsequence 
    sub.pop_back();
    printsub(ind+1, sub, arr, n);
 
}

int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> sub;
    printsub(0, sub, arr, n);
    return 0;
}
