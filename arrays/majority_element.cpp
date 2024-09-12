int majorityElement(vector<int> arr) {
	int ele, cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		if(cnt == 0){
			cnt = 1;
			ele = arr[i];
		}
		else if(arr[i] == ele) cnt++;
		else cnt--;
	}
	//needed only when majority element is not guranteed
	int cntele = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == ele) cntele++;
	}
	if(cntele <= arr.size()/2) ele = -1; //no majority element
	return ele;
}