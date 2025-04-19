class Solution {
    private:
        long long totaltimetoeat(vector<int> &piles, int k){
            long long totaltime = 0;
            for(auto ele : piles){
                totaltime += ceil(ele/(1.0*k));
            }
            return totaltime;
        }
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int maxpileval = *max_element(piles.begin(), piles.end());
            int low = 1, high = maxpileval;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(totaltimetoeat(piles, mid) <= h){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            return low;
        }
    };