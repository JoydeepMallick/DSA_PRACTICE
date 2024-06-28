#include <bits/stdc++.h>
#include <vector>
using namespace std;
/////////////////////debug/////////////////////////
void print(vector<int> arr) {
  cout << "DBG : ";
  for (auto ele : arr)
    cout << ele << " ";
  cout << endl;
}

void printDP(vector<vector<int>> &dp) {
  for (auto it : dp) {
    for (auto ele : it)
      cout << ele << " ";
    cout << endl;
  }
}
//////////////////////////////////////////////////

class SolutionRecursive {
private:
  int f(vector<int> &nums, int ind, int prevind, vector<int> &sub,
        vector<int> &ans, vector<vector<int>> &dp) {
    if (ind == nums.size()) {
      print(sub);
      if (sub.size() > ans.size())
        ans = sub;
      return 0;
    }
    /* if (dp[ind][prevind + 1] != -1) { */
    // this can use dp to store length but we need to keep in mind that we are
    // not storing indexes in DP to get subset so answer will be wrong for test
    // case like [5,9,18,90,180,360,720] where length returns 6 but subset is 5.
    // If we try to extend dp by storing all possible subsets we will need huge
    // space
    /* return dp[ind][prevind + 1]; */
    /* } */
    //[1, 3, 6, 9, 27] -> [1,3,9,27] so we skip 6 even if its divisible by 3
    int val = 0;
    if (sub.size() == 0 || nums[ind] % nums[prevind] == 0) {
      sub.push_back(nums[ind]);
      int take = 1 + f(nums, ind + 1, ind, sub, ans, dp); // lets take
      sub.pop_back();
      int nottake =
          0 + f(nums, ind + 1, prevind, sub, ans, dp); // lets not take
      val = max(take, nottake);
    } else {
      val = f(nums, ind + 1, prevind, sub, ans, dp); // skip
    }
    return dp[ind][prevind + 1] =
               val; // no fixed ending point and varible starting point
  }

public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // if x < y < z then if y%x = 0 and z%y = 0 then we can definitely claim z%y
    // = 0
    vector<int> sub, ans;
    vector<vector<int>> dp(
        n, vector<int>(n + 1, -1)); // prevind is 1 based ind is 0 based
    int maxsize = f(nums, 0, -1, sub, ans, dp);
    cout << "maxsize : " << maxsize << endl;
    printDP(dp);
    return ans;
  }
};

// algorithmic DP similar to LIS
class Solution {

public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // if x < y < z then if y%x = 0 and z%y = 0 then we can definitely claim
    // z%y= 0
    vector<int> ans, dp(n + 1, 1), hash(n, 0);
    // at least 1 element will always be the size of answer
    int maxLDSlength = 0;
    int LDSendingindex = 0; // asuming at worst case 1 element exist
    for (int ind = 1; ind < n; ind++) {
      hash[ind] = ind;
      for (int prevind = 0; prevind < ind; prevind++) {
        if (nums[ind] % nums[prevind] == 0 && (1 + dp[prevind]) > dp[ind]) {
          dp[ind] = 1 + dp[prevind];
          hash[ind] = prevind;
        }
      }
      if (dp[ind] > maxLDSlength) {
        maxLDSlength = dp[ind];
        LDSendingindex = ind;
      }
    }
    // backtrack DP for ans
    int ind = LDSendingindex;
    ans.push_back(nums[ind]);
    while (ind != hash[ind]) {
      ind = hash[ind];
      ans.push_back(nums[ind]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution ss;
  vector<int> nums = {5, 9, 18, 90, 180, 360, 720};
  for (auto ele : ss.largestDivisibleSubset(nums))
    cout << ele << " ";
  cout << endl;
  /* nums = {3, 8, 4, 16}; */
  /* for (auto ele : ss.largestDivisibleSubset(nums)) */
  /* cout << ele << " "; */
  /* cout << endl; */
  /* nums = {1, 3, 6, 9, 27}; */
  /* for (auto ele : ss.largestDivisibleSubset(nums)) */
  /* cout << ele << " "; */
  /* cout << endl; */

  return 0;
}
