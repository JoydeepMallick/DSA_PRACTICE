#include <bits/stdc++.h>
#include <vector>
using namespace std;

int long_cmn_substr(string &s1, string &s2) {
  int s1len = s1.size(), s2len = s2.size();
  vector<vector<int>> dp(s1len + 1, vector<int>(s2len + 1, -1));
  // 1 based indexing
  for (int i = 0; i <= s1len; i++)
    dp[i][0] = 0; // base case when index of s1 out of bound
  for (int i = 0; i <= s2len; i++)
    dp[0][i] = 0; // base case when index of s2 out of bound

  int ans = 0;
  for (int i = 1; i <= s1len; i++) {
    for (int j = 1; j <= s2len; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return ans;
}

int main() {
  string s1 = "abcjklp", s2 = "acjkp";
  cout << long_cmn_substr(s1, s2) << endl;
  return 0;
}
