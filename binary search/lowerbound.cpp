int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n-1, ans = n;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(arr[mid] >= x) {
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}	
	}
	return ans;
}


/*

std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();  <-- finds index
std::lower_bound(arr.begin(), arr.end(), x) - arr.begin() + 1;  <-- finds position
*std::lower_bound(arr.begin(), arr.end(), x) <-- find value

*/
