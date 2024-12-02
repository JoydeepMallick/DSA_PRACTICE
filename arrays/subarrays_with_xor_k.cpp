int subarraysWithSumK(vector < int > arr, int k) {
    int xorval = 0; // no element
    unordered_map<int, int> mpp;
    mpp[xorval]++;// 0->1
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        xorval = xorval ^ arr[i];
        int ele = xorval ^ k;
        if(mpp.find(ele) != mpp.end()){
            cnt += mpp[ele];
        }
        mpp[xorval]++;
    } 
    return cnt;
}