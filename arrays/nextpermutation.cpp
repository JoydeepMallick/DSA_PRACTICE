#include <bits/stdc++.h>
using namespace std;

vector<int> next_perm(vector<int> perm){
    int n = perm.size();

    int ind = -1;
    for(int i = n-2; i > 0; i--){
        if(perm[i] < perm[i+1]){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        reverse(perm.begin(), perm.end());
        return perm;
    }

    for(int i = n-1; i > ind; i--){
        if(perm[i] > perm[ind]){
            swap(perm[i], perm[ind]);
            break;
        }
    }

    reverse(perm.begin()+ind+1, perm.end());

    return perm;
}

int main(){
    vector<int> perm = {2,1,5,4,3,0,0};
    //ans must be 2 3 0 0 1 4 5
   
    //using STL function next_permutation
    next_permutation(perm.begin(), perm.end());
    for(int i=0; i<perm.size(); i++){
        cout << perm[i] << " ";
    }
    cout << endl;

    vector<int> perm2 = {2,1,5,4,3,0,0};
    //writing our own function
    for(auto ele : next_perm(perm2)){
        cout << ele << " ";
    }    
    
    return 0;
}
