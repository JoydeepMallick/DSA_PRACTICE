class Solution {
    public:
        int totaltrips(vector<int> &wt, int cap){
            int wtsum = 0, tripcnt = 0;
            for(auto w : wt){
                if(wtsum + w > cap){
                    tripcnt++;
                    wtsum = w;
                }else wtsum += w;
            }
            if(wtsum > 0) tripcnt++;
            return tripcnt;
        }
    
        int shipWithinDays(vector<int>& weights, int days) {
            int low = *max_element(weights.begin(), weights.end());
            int high = accumulate(weights.begin(), weights.end(), 0);
            while(low <= high){
                int mid = low + (high - low)/2;
                if(totaltrips(weights, mid) <= days) high = mid-1;
                else low = mid+1;
            }
            return low;
        }
    };