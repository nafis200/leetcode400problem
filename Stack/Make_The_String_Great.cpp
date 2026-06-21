// 0 - 6 months:
// Google (3)

// 6 months ago:
// Amazon (3) — Meta (2) — Apple (2) — Accenture (2) — Yahoo (2) — BlackStone
// (2)

// Problem_Link:
// https://leetcode.com/problems/make-the-string-great/description/

#include <bits/stdc++.h>
using namespace std;
string makeGood(string s) {
    string ans = "";
    int n = s.size() - 1;
    stack<char>st;
    for(int i = 0; i <= n; i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        char x = st.top();
        if(abs(s[i] - x) == 32){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "abBAcC";
  string ans = makeGood(s);
  cout << ans << "\n";
}