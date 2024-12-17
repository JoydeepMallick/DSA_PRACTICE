int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> tmp;
    int left = low, right = mid+1;

    int cnt = 0;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }else{
            cnt += (mid - left + 1);
            tmp.push_back(arr[right]);
            right++;
        }
    }
    //fill rest
    while(left <= mid){
        tmp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        tmp.push_back(arr[right]);
        right++;
    }

    //fill web
    for(int i = low; i <= high; i++){
        arr[i] = tmp[i - low];
    }

    return cnt;
}

int mergesort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low >= high) return 0;
    int mid = low + (high-low)/2;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int numberOfInversions(vector<int>&arr, int n) {
    int ans = mergesort(arr, 0, n-1);
    return ans;
}