class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int r = matrix.size(), c = matrix[0].size();
            int row = 0, col = c-1;
            while(row < r && col >= 0){
                if(matrix[row][col] == target) return true;
                else if(matrix[row][col] > target) col--;
                else row++; 
            }
            return false;
        }
    };