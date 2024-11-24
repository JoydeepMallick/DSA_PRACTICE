#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
	int n = arr.size();
	vector<int> ans;
	int need = floor(n/3) + 1;
	int cnt1 = 0, cnt2 = 0, ele1, ele2;
	for(int i = 0; i < n; i++){
		if(cnt1 == 0 && ele2 != arr[i]){
			cnt1 = 1;
			ele1 = arr[i];
		}
		else if(cnt2 == 0 && ele1 != arr[i]){
			cnt2 = 1;
			ele2 = arr[i];
		}
		else if(ele1 == arr[i]) cnt1++;
		else if(ele2 == arr[i]) cnt2++;
		else{
			cnt1--;
			cnt2--;
		}
	}
	//check if such elements are actually majority
	cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++){
		if(ele1 == arr[i]) cnt1++;
		else if(ele2 == arr[i]) cnt2++;
	}

	if(cnt1 >= need) ans.push_back(ele1);
	if(cnt2 >= need) ans.push_back(ele2);
	return ans;
}

int main(){
    vector<int> nums = {1,2,1,1,3,3,2,2};
    vector<int> ans = majorityElement(nums);   
    for(auto ele : ans) cout << ele << " ";
    cout << endl;
    return 0;
}
