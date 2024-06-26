#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> LIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n, 0);
    int LISlength = dp[0];
    int lastindex = -1;

    for (int cur_ind = 1; cur_ind < n; cur_ind++) {
      hash[cur_ind] = cur_ind;

      for (int prev_ind = 0; prev_ind < cur_ind; prev_ind++) {
        if (nums[cur_ind] > nums[prev_ind] && dp[cur_ind] < 1 + dp[prev_ind]) {
          dp[cur_ind] =
              1 + dp[prev_ind]; // we pick the dp value which satisfy num LIS
                                // and also is maximum among all satisfying
          hash[cur_ind] = prev_ind; // do not do hash[prev_ind] else we will end
                                    // up with a sequence of just 2 always
        }
      }
      if (LISlength < dp[cur_ind]) {
        LISlength = dp[cur_ind];
        lastindex = cur_ind; // index for which DP value is maximum
      }
    }

    // backtracking hash for answer
    vector<int> LIS;
    LIS.push_back(nums[lastindex]);
    while (hash[lastindex] != lastindex) {
      lastindex = hash[lastindex];
      LIS.push_back(nums[lastindex]);
    }
    reverse(LIS.begin(), LIS.end());
    return LIS;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {5, 4, 11, 1, 16, 8};
  for (auto ele : sol.LIS(arr)) {
    cout << ele << " ";
  }
  cout << endl;
}
