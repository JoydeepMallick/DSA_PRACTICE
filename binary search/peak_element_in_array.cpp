
// my solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //BS by trying to move to nearest peak out of all peaks present
        int n = nums.size();
        //edge cases
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            //check if peak
            if((mid == 0 || nums[mid-1] < nums[mid])
            && (mid == n-1 || nums[mid+1] < nums[mid])){
                //peak found
                return mid;
            }
            //is the point lying on increasing curve
            else if((mid == 0 || nums[mid-1] < nums[mid])
            && (mid == n-1 || nums[mid+1] > nums[mid])){
                //go right
                low = mid+1;
            }
            //is this point lying on decreasing curve
            else if((mid == 0 || nums[mid-1] > nums[mid])
            && (mid == n-1 || nums[mid+1] < nums[mid])){
                //go left
                high = mid-1;
            }
            //is point in the valley x-1 > x < x+1
            else{
                //both sides can have potential peak, go any one way
                low = mid+1;
            }
        }
        return -1;
    }
};
