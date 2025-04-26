// o(n) solution

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int ans = k;
            for(auto ele : arr){
                if(ele <= ans) ans++;
            }
            return ans;
        }
    };


    //o(log n) solution
    class Solution {
        public:
            int findKthPositive(vector<int>& arr, int k) {
                int n = arr.size();
                int low = 0, high = n-1;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    int misscnt = arr[mid] - mid-1;
                    if(misscnt >= k) high = mid-1;
                    else low = mid+1;
                }
                int ans = k + high + 1;
                return ans;
            }
        };  