class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int r = matrix.size(), c = matrix[0].size();
            int low = 0, high = r*c-1; //all valid elements positions from 0
            while(low <= high){
                int mid = (low + high)/2;
                int i = mid/c, j = mid%c;
                if(matrix[i][j] == target){
                    return true;
                }else if(matrix[i][j] < target){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            return false;
        }
    };