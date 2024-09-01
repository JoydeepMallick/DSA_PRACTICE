#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &arr, int n){
    //find first zero 
    int j = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;//no zero found

    //swap and shift in one pass
    for(int i = j+1; i < n; i++ ){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;//point at 0 again
        }
    }
}

int main(){
    vector<int> arr = {1,0,2,3,2,0,0,4,5,1};
    int n = arr.size();
    moveZeros(arr, n);
    cout << "Array after moving zeros to end: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
