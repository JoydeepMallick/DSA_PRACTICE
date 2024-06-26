#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution1 {
private:
  int f(vector<int> &nums, int cur_ind, int prev_ind, vector<vector<int>> &dp) {
    if (cur_ind == nums.size())
      return 0;
    if (dp[cur_ind][prev_ind + 1] != -1)
      return dp[cur_ind][prev_ind + 1];
    int ans = 0;
    if (prev_ind == -1 || nums[cur_ind] > nums[prev_ind]) {
      int take = 1 + f(nums, cur_ind + 1, cur_ind, dp);
      int nottake = 0 + f(nums, cur_ind + 1, prev_ind, dp);
      ans = max(take, nottake);
    } else {
      ans = 0 + f(nums, cur_ind + 1, prev_ind, dp);
    }
    return dp[cur_ind][prev_ind + 1] = ans;
  }

public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(nums, 0, -1, dp);
  }
};

// tabulation can be done (order of prev ind does not matter)
class Solution2 {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int cur_ind = n - 1; cur_ind >= 0; cur_ind--) {
      for (int prev_ind = cur_ind - 1; prev_ind >= -1; prev_ind--) {
        int ans = 0;
        if (prev_ind == -1 || nums[cur_ind] > nums[prev_ind]) {
          int take = 1 + dp[cur_ind + 1][cur_ind + 1];
          int nottake = 0 + dp[cur_ind + 1][prev_ind + 1];
          ans = max(take, nottake);
        } else {
          ans = 0 + dp[cur_ind + 1][prev_ind + 1];
        }
        dp[cur_ind][prev_ind + 1] = ans;
      }
    }

    // DP array
    cout << "-----------DP array------------\n";
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    cout << "-----------DP array------------\n";
    // debug end
    return dp[0][-1 + 1];
  }
};

class Solution3 {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int cur_ind = n - 1; cur_ind >= 0; cur_ind--) {
      for (int prev_ind = -1; prev_ind < cur_ind; prev_ind++) {
        int ans = 0;
        if (prev_ind == -1 || nums[cur_ind] > nums[prev_ind]) {
          int take = 1 + dp[cur_ind + 1][cur_ind + 1];
          int nottake = 0 + dp[cur_ind + 1][prev_ind + 1];
          ans = max(take, nottake);
        } else {
          ans = 0 + dp[cur_ind + 1][prev_ind + 1];
        }
        dp[cur_ind][prev_ind + 1] = ans;
      }
    }
    return dp[0][-1 + 1];
  }
};

// space optimization
class Solution4 {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> cur(n + 1, 0), next(n + 1, 0);
    for (int cur_ind = n - 1; cur_ind >= 0; cur_ind--) {
      for (int prev_ind = cur_ind - 1; prev_ind >= -1; prev_ind--) {
        int ans = 0 + next[prev_ind + 1]; // nottake
        if (prev_ind == -1 || nums[cur_ind] > nums[prev_ind]) {
          int take = 1 + next[cur_ind + 1];
          ans = max(ans, take);
        }
        cur[prev_ind + 1] = ans;
      }
      next = cur;
    }
    return next[-1 + 1];
  }
};

// a different Dp approach with O(n) space
class Solution5 {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // base case or in worst situation
    int ans = dp[0];
    for (int cur_ind = 1; cur_ind < n; cur_ind++) {
      for (int prev_ind = 0; prev_ind < cur_ind; prev_ind++) {
        if (nums[cur_ind] > nums[prev_ind]) {
          dp[cur_ind] = max(dp[cur_ind], 1 + dp[prev_ind]);
        }
      }
      ans = max(ans, dp[cur_ind]);
    }
    return ans;
  }
};

int main() {
  Solution2 sol;
  vector<int> arr = {5, 4, 11, 1, 16, 8};
  cout << sol.lengthOfLIS(arr) << endl;
}
