#include<vector>

// normal solution
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	int n = arr.size();
	for(int i = 0; i < n; i++){
		int start = arr[i][0];
		int end = arr[i][1];
		if(!ans.empty() && end <= ans.back()[1] ) continue;//lies within the combined range already
		for(int j = i+1; j < n; j++){
			if(arr[j][0] <= end){
				end = max(end, arr[j][1]);
			}else{
				break;
			}
		}
		ans.push_back({start, end});//no updation on start needed since sorted array will always smallest start at first
	}
	return ans;
}

//most optimal
vector<vector<int>> mergeOverlappingIntervals_optimal(vector<vector<int>> &arr){
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	int n = arr.size();
	for(int i = 0; i < n; i++){
		int start = arr[i][0];
		int end = arr[i][1];
		if(ans.empty() || start > ans.back()[1] ){
			//new range found
			ans.push_back(arr[i]);
		}
		else{
			// in same range so update end
			ans.back()[1] = max(end, ans.back()[1]);
		}
	}
	return ans;
}

