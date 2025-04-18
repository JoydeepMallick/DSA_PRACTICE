class Solution {
    public:
        int mySqrt(int x) {
            long long low = 0, high = x;
            long long ans = -1;
            while(low <= high){
                long long mid = low + (high - low)/2;
                long long sq = mid*mid;
                if(sq == x){
                    ans = mid;
                    break;
                }
                else if(sq < x){
                    ans = mid;//maximum possible value
                    low = mid+1;
                } 
                else high = mid-1;
            }
            return (int)ans;
        }
    };