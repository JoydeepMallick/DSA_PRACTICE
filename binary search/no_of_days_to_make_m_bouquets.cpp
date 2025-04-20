class Solution {
    private:
        int noofbouquets(vector<int>& bloomDay, int k, int day){
            int c = 0, bqcnt = 0; 
            for(auto d : bloomDay){
                if(d <= day) c++;
                else{
                    bqcnt += c/k;
                    c = 0;
                }
            }
            if(c > 0) bqcnt += c/k;
            return bqcnt;
        }
    
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            int low = *min_element(bloomDay.begin(), bloomDay.end());
            int high = *max_element(bloomDay.begin(), bloomDay.end());
            int ans = -1;
            while(low <= high){
                int mid = low + (high - low)/2;
                int bouquetcnt = noofbouquets(bloomDay, k, mid);
                if(bouquetcnt >= m) {
                    ans = mid;
                    high = mid-1;//try improving answer
                }
                else low = mid+1;
            }
            return ans;
        }
    };