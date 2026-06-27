// 0 - 3 months: Meta (17) — Grammarly (4) — Google (3) — Microsoft (3)
// 0 - 6 months: Amazon (3) — Paytm (2)
// 6 months ago: Apple (5) — Adobe (4) — Oracle (2) — Goldman Sachs (2) — Uber
// (2)

// Problem_Link:
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
  int n = s.size();
  string st;
  for (int i = 0; i < n; i++) {
    if (st.empty()) {
      st.push_back(s[i]);
    } else {
      if (st.back() == s[i]) {
        st.pop_back();
      } else {
        st.push_back(s[i]);
      }
    }
  }
  return st;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abbaca";
  string ans = removeDuplicates(s);
  cout << ans << "\n";
}