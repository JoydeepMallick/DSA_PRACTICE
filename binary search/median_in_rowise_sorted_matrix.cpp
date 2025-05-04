int upperBound(vector<int> &row, int ele){
    int low = 0, high = row.size()-1;
    int ans = row.size();
    while(low <= high){
        int mid = (low + high)/2;
        if(row[mid] > ele){
            ans = mid;
            high = mid-1;//improve ans
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int lessthanequalCnt(vector<vector<int>> &mat, int ele){
    int cnt = 0;
    for(auto row : mat){
        // cnt += upper_bound(row.begin(), row.end(), ele) - row.begin();
        cnt += upperBound(row, ele);

    }
    return cnt;
}


int median(vector<vector<int>> &matrix, int m, int n) {
    int rows = m, cols = n;
    int low = INT_MAX, high = INT_MIN;
    for(int r = 0; r < rows; r++){
        low = min(low, matrix[r][0]);
        high = max(high, matrix[r][cols-1]);
    }
    int mincnt = (rows*cols+1)/2;
    while(low <= high){
        int mid = (low + high)/2;
        int ltecnt = lessthanequalCnt(matrix, mid);
        if(ltecnt < mincnt) low = mid+1;
        else high = mid-1;
    }
    return low;
}