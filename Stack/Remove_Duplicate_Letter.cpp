// 0 - 3 months:
// Microsoft (2)

// 0 - 6 months:
// Meta (2) — TikTok (2) — Paytm (2)

// 6 months ago:
// Google (14) — Amazon (9) — Bloomberg (7) — Expedia (6) — ByteDance (3) — Zoho (3) — FactSet (3) — Oracle (2) — Increff (2)

// Problem_Links: https://leetcode.com/problems/remove-duplicate-letters/description/

#include<bits/stdc++.h>
using namespace std;

  string removeDuplicateLetters(string s) {
  unordered_map<char, int> mp;

  for (char c : s) {
    mp[c]++;
  }

  stack<char> st;
  vector<bool> vis(256, false);

  for (char c : s) {
    mp[c]--;
    if(vis[c]) continue;

    while (!st.empty() && st.top() > c && mp[st.top()] > 0) {
      vis[st.top()] = false;
      st.pop();
    }

    if (!vis[c]) {
      st.push(c);
      vis[c] = true;
    }
  }

  string ans;

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());

  return ans;
}    

int32_t main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    string s = "cbacdcbc";
    s = removeDuplicateLetters(s);

    cout << s << "\n";
}