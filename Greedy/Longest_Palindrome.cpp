// 0 - 3 months: Google (4)
// 0 - 6 months: Amazon (4) — Meta (2) — Bloomberg (2)
// 6 months ago: Microsoft (5) — Oracle (3) — Yahoo (3) — Apple (2) — Walmart
// Labs (2)

// Problem_Link: https://leetcode.com/problems/longest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;
int longestPalindrome(string s) {
  vector<int> cnt(300, 0);

  for (auto i : s) {
    cnt[i - 'A']++;
  }
  bool odd = false;
  int sum = 0;
  for (auto i : cnt) {
    if (i % 2 == 0) {
      sum += i;
    } else {
      sum += i - 1;
      odd = true;
    }
  }
  if (odd) {
    sum++;
  }
  return sum;
}
int32_t main() {
  string s = "abccccdd";
  int ans = longestPalindrome(s);
  cout << ans << "\n";
}