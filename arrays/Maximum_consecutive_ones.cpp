#include <bits/stdc++.h>
using namespace std;

int maxconsecutiveones(vector<int> &arr) {
    int count = 0, maxcount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;
            maxcount = max(maxcount, count);
        } else {
            count = 0;
        }
    }
    return maxcount;
}

int main(){
    vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1};
    cout << "Maximum consecutive ones: " << maxconsecutiveones(arr) << endl;
    return 0;
}
