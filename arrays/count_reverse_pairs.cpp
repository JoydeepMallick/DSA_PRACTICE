void merge(vector<int> &arr, int low, int mid, int high){
    int left = low, right = mid +1;
    vector<int> tmp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            tmp.push_back(arr[left]);
            left++;
        } else {
            tmp.push_back(arr[right]);
            right++;
        }
    }
    //fill remaining in tmp
    while(left <= mid){
        tmp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        tmp.push_back(arr[right]);
        right++;
    }

    //rearrange array
    for (int i = low; i <= high; i++) {
        arr[i] = tmp[i-low];
    }
    
}

int cntpairs(vector<int> &arr, int low, int mid, int high){
    int left, right = mid+1;
    int cnt = 0;
    for(left = low; left <= mid; left++){
        while(right <= high && arr[left] > 2 * arr[right]){
            right++;
        }
        cnt += (right - (mid+1));
    }
    return cnt;
}

int mergesort(vector<int> &arr, int low , int high){
    
    int cnt = 0;
    if(low >= high) return 0;
    int mid = low + (high - low)/2;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid+1, high);
    cnt += cntpairs(arr, low, mid, high);
    //avoid tampering merge operation
    merge(arr, low, mid, high); 
    return cnt;
}


int team(vector <int> & skill, int n)
{
    int cnt = mergesort(skill, 0, n-1);
    return cnt;
        
}
