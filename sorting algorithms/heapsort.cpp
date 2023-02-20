#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i = 0 ;i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}



/* http://cs.middlesexcc.edu/~schatz/csc236/handouts/heapsort.html */

/*
 * This heapsort max heapify array once....
 *
 * and then for each swap and created a sorted region from end(largest goes at last) 
 * and just restore heap property by sifting that swapped element to correct space
 *
 */

void siftdown(int arr[], int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) {
        int lchild = root * 2 + 1;            // subscript of left child
        int swapind = root;
        if (arr[swapind] < arr[lchild])
            swapind = lchild;                 // should swap root & left child
        if (lchild + 1 <= end && arr[swapind] < arr[lchild+1])
            swapind = lchild + 1;              // should swap root & right child
        if (swapind != root) {              // if one of children is greater
            swap(arr[root],arr[swapind]);     // swap root & larger child
            root = swapind;
        }
        else
            return;
        //checking
        print(arr,end+1);
    }
}

void heapify(int arr[], int size) {
    int start = size/2 - 1;                   // last non leaf
    while (start >= 0) {
        siftdown(arr, start, size-1);
        start = start - 1;
    }
}

void heapsort(int arr[], int size) {
    cout << "\n_________________start heapify _________________\n";
    heapify(arr,size);
    cout << "\n__________________end heapify __________________\n";
    int last = size -1;                       // subscript of last item
    while (last > 0) {
        print(arr, last+1);
        cout << "\n_________________swapped first and last for sorting _________________\n";
        swap(arr[last], arr[0]);
        print(arr, last+1);
        last = last - 1;
        cout << "\n________repair using sift down the remaining unsorted region ________\n";
        siftdown(arr, 0, last);
    }
}

int main(){
    //int n = 10;
    //int arr[n] = {4,7,1,10, 6,13,1,9,15,3};
    int n = 8;
    int arr[n] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    cout << "Before heap sorting : ";
    print(arr,n);
    heapsort(arr, n);
    cout << "After heap sorting : ";
    print(arr, n);
    return 0;
}
