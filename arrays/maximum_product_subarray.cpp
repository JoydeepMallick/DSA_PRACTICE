#include<vector>
#include <climits>

int subarrayWithMaxProduct(vector<int> &arr){
	int prefprod = 1, suffprod = 1;
	int n = arr.size(), maxprod = INT_MIN;
	for(int i = 0; i < n; i++){
		if(prefprod == 0) prefprod = 1;
		if(suffprod == 0) suffprod = 1;
		prefprod = prefprod * arr[i];
		suffprod = suffprod * arr[n-i-1];
		maxprod = max({maxprod, suffprod, prefprod});
	}
	return maxprod;
}