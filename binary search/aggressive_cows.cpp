class Solution {
    public:
        int allplaced(vector<int> &pos, int dist, int m){
            int lastpos = pos[0], cnt = 1;
            for(int i = 1; i < pos.size(); i++){
                if(pos[i] - lastpos >= dist){
                    cnt++;
                    lastpos = pos[i];
                }
            }
            if(cnt >= m) return true;
            else return false;
        }
    
        int maxDistance(vector<int>& position, int m) {
            sort(position.begin(), position.end());
            int low = 1, high = position[position.size()-1] - position[0];
            while(low <= high){
                int mid = (low + high)/2;
                if(allplaced(position, mid, m)) low = mid+1;
                else high = mid-1;
            }
            return high;
        }
    };