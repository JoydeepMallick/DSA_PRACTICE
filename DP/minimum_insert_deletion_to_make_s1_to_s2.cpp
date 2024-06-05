#include <bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2) {
  int s1len = s1.size(), s2len = s2.size();
  vector<int> prev(s2len + 1, 0), cur(s2len + 1, 0);
  for (int i = 1; i <= s1len; i++) {
    for (int j = 1; j <= s2len; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        cur[j] = 1 + prev[j - 1];
      } else {
        cur[j] = max(cur[j - 1], prev[j]);
      }
    }
    prev = cur;
  }
  return cur[s2len];
}

// same problem concept as minimum insertion and deletions to make a given
// string 1 to string 2
int minDistance(string word1, string word2) {
  return word1.size() + word2.size() - 2 * LCS(word1, word2);
}

int main() {
  string s1 = "abcd", s2 = "anc";
  cout << minDistance(s1, s2) << endl;
  return 0;
}
