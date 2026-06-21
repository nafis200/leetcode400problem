
// Google (18) — Amazon (16) — Bloomberg (14) — Meta (13) — Microsoft (8) —
// Turing (7) — LinkedIn (6) — Apple (5) — TikTok (4) — IBM (3)

// Problem_Link: https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n) space o(n)

bool isValid(string s) {
  stack<char> st;
  for (auto i : s) {
    if (i == '(' || i == '{' || i == '[') {
      st.push(i);
    } else {
      if (st.empty()) {
        return false;
      } else if (i == ')' && st.top() == '(') {
        st.pop();
      } else if (i == '}' && st.top() == '{') {
        st.pop();
      } else if (i == ']' && st.top() == '[') {
        st.pop();
      }
      else{
        st.push(i);
      }
    }
  }
  if (st.empty()) {
    return true;
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "()[]{}";
  bool ans = isValid(s);
  cout << ans << "\n";
}