#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];//choose first element as pivot 
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }

        while(arr[j] > pivot && j >= low+1){
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high){
    if(low < high){
        int parInd = partition(arr, low, high);
        quicksort(arr, low, parInd - 1);
        quicksort(arr, parInd + 1, high);
    }
}

void qsort(vector<int> &arr, int size){
    quicksort(arr, 0, size-1);
}

int main(){
    vector<int> arr = {1,3,2,4,7,9,5,6};
    qsort(arr, arr.size());
    for(auto it : arr) cout << it << " ";
    return 0;
}
