#include <bits/stdc++.h>
using namespace std;

string LCS_string(string &s, string &t) {
  int slen = s.size(), tlen = t.size();

  // 2d dp is 1 based hence indexing will be handled like i-1 and j-1
  vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1, 0));
  // base case row 0 and column 0 is all 0 representing out of bounds
  int i = slen, j = tlen;
  for (int i = 1; i <= slen; i++) {
    for (int j = 1; j <= tlen; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][i - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << "LCS length : " << dp[slen][tlen] << endl;

  string ans = "";
  // fill with dummy string value of size of LCS
  for (int i = 0; i < dp[slen][tlen]; i++) {
    ans += "-";
  }
  int ind = dp[slen][tlen] - 1;

  i = slen, j = tlen;
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      ans[ind--] = s[i - 1]; // ans[ind--]  = s[j-1];
      i--, j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  return ans;
}

int main() {
  string s = "abcde", t = "bdgek";
  string ans = LCS_string(s, t);
  cout << "LCS string : " << ans << endl;
  return 0;
}
