#include <bits/stdc++.h>
using namespace std;

/*

   n = 4

   4 4 4 4 4 4 4
   4 3 3 3 3 3 4
   4 3 2 2 2 3 4
   4 3 2 1 2 3 4
   4 3 2 2 2 3 4
   4 3 3 3 3 3 4
   4 4 4 4 4 4 4


 */

int main() {
  int n = 4;
  for (int r = 0; r < 2 * n - 1; r++) {
    for (int c = 0; c < 2 * n - 1; c++) {
      int top = r;
      int left = c;
      int right = (2 * n - 1) - r - 1;
      int bottom = (2 * n - 1) - c - 1;
      cout << n - min({top, left, bottom, right}) << " ";
    }
    cout << "\n";
  }
  return 0;
}
