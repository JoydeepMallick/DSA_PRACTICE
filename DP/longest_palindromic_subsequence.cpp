#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2) {
  int s1len = s1.size(), s2len = s2.size();
  vector<int> prev(s2len + 1, 0), cur(s2len + 1, 0);
  for (int i = 1; i <= s1len; i++) {
    for (int j = 1; j <= s2len; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        cur[j] = 1 + prev[j - 1];
      } else {
        cur[j] = max(prev[j], cur[j - 1]);
      }
    }
    prev = cur;
  }
  return cur[s2len];
}

int longestPalindromeSubseq(string s) {
  string revs = s;
  reverse(revs.begin(), revs.end());
  return LCS(s, revs);
}

int main() {
  string s = "bbbab";
  cout << longestPalindromeSubseq(s) << endl;
  return 0;
}
