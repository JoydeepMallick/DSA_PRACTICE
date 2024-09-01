#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& v1, vector<int>& v2){
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> res;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(v1[i] == v2[j]){
            res.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i] < v2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return res;
}

int main(){
    vector<int> v1 = {1, 3, 3, 4, 5, 7};
    vector<int> v2 = {2, 3, 3, 5, 6};
    cout << "After intersection: ";
    for(auto ele : intersection(v1,v2)){
        cout << ele << " ";
    }
    return 0;
}
