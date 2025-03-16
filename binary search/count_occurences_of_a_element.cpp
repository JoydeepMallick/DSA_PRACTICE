#include<algorithm>

int count(vector<int>& arr, int n, int x) {
	int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	if(lb == n || arr[lb] != x){
		return 0;
	}
	int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	return ub - lb;
}
