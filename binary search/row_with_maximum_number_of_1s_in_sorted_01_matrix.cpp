int rowWithMax1s(vector<vector<int>> &mat, int n, int m) {
    int rows = n, cols = m;
    int maxcnt = -1, rowind = -1;
    for(int i = 0; i < rows; i++){
        int low = 0, high = cols-1;
        //find lower bound of 1
        int lb = cols; // worst case
        while(low <= high){
            int mid = (low + high)/2;
            if(mat[i][mid] >= 1){
                lb = mid;
                //improve lb
                high = mid-1;
            }else{
                low = mid+1;
            }
        } 
        int cnt = cols - lb;
        if(cnt > 0 && cnt > maxcnt){
            maxcnt = cnt;
            rowind = i;
        }
    } 
    return rowind;    
}


//using STL
int rowWithMax1s(vector<vector<int>> &mat, int n, int m) {
    int maxcnt = 0, rowind = -1;
    for(int row = 0; row < n; row++){
        int lb = lower_bound(mat[row].begin(), mat[row].end(), 1) - mat[row].begin();
        int cnt = m - lb;
        if(cnt > maxcnt){//enter only if cnt >= 1
            maxcnt = cnt;
            rowind = row;
        }
    } 
    return rowind;    
}                       