class Solution {
    public:
        int findMaxInCol(vector<vector<int>>& mat, int col){
            int row = mat.size();
            int ind = -1, maxval = -1;
            for(int r = 0; r < row; r++){
                if(mat[r][col] > maxval){
                    maxval = mat[r][col];
                    ind = r;
                }
            }
            return ind;
        }
    
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int r = mat.size(), c = mat[0].size();
            int low = 0, high = c-1;
            while(low <= high){
                int mid = (low + high)/2;
                int maxrow = findMaxInCol(mat, mid);//up and down property satisfied here
                int left = (mid-1 >= 0) ? mat[maxrow][mid-1] : -1;
                int right = (mid+1 < c) ? mat[maxrow][mid+1] : -1;
                int cur = mat[maxrow][mid];
                if(left < cur && right < cur) return {maxrow, mid};
                else if(left > cur){// go left > > or if > < situation exist
                    high = mid-1;
                }else{//go right < <
                    low = mid+1;
                } 
            }
            return {-1,-1};
        }
    };