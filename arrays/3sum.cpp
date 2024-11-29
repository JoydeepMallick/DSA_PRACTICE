#include<bits/stdc++.h>
using namespace std;
// Better solution
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> unique;
    for(int i = 0; i < n; i++){
        set<int> hashset;
        for(int j = i+1; j < n; j++){
            int arrk = -(arr[i] + arr[j]);
            if(hashset.find(arrk) != hashset.end()){
                vector<int> tmp = {arr[i], arr[j], arrk};
                sort(tmp.begin(), tmp.end());
                unique.insert(tmp);
            }
            hashset.insert(arr[j]);//before moving to next j
        }
    }
    vector<vector<int>> triplets(unique.begin(), unique.end());
    return triplets;
}

//optimal code
vector<vector<int>> triplets_optimal(int n, vector<int> &arr)
{
    vector<vector<int>> triplets;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(k > j && k < n){
            int s = arr[i] + arr[j] + arr[k];
            if(s < 0){
                //increase j
                j++;
                while(j < n && arr[j-1] == arr[j]){
                    j++;
                }
            }else if(s > 0){
                //decrease k
                k--;
                while(k > 0 && arr[k+1] == arr[k]){
                    k--;
                }
            }else if(s == 0){
                //triplet found
                triplets.push_back(vector<int> ({arr[i], arr[j], arr[k]}));
                k--;j++;
                while(j < n && arr[j] == arr[j-1]){
                    j++;
                }
                while(k > 0 && arr[k] == arr[k+1]){
                    k--;
                }
            }
        }
    }
    return triplets;
}


