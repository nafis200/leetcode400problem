

// 0 - 3 months:
// Meta (20) — Bloomberg (7)

// 0 - 6 months:
// TikTok (3) — Oracle (2)

// 6 months ago:
// Google (15) — Amazon (13) — Microsoft (9) — Apple (3) — Walmart Labs (3) —
// Adobe (2) — Tencent (2) — Snap (2) — GE Digital (2)

// problem Link:
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

// time o(nlogn) space o(n)

// string minRemoveToMakeValid(string s) {
//   string t = "";
//   stack<int> st;
//   set<int> se;
//   for(int i = 0; i < s.size(); i++){
//      if(s[i] == ')' && st.empty()){
//            se.insert(i);
//      }
//      else if(s[i] == '('){
//         st.push(i);
//      }
//      else{
//          if(!st.empty() && s[i] == ')'){
//              st.pop();
//          }
//      }
//   }

//   while(!st.empty()){
//      int top = st.top();
//      st.pop();
//      se.insert(top);
//   }

//   for(int i = 0; i < s.size(); i++){
//       if(se.find(i) == se.end()){
//           t += s[i];
//       }
//   }
//   return t;
// }

// time o(n) space o(n)

string minRemoveToMakeValid(string s) {
    int n = s.size();
    vector<bool> remove(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else if (s[i] == ')') {
            if (st.empty()) {
                remove[i] = true;
            } else {
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        remove[st.top()] = true;
        st.pop();
    }

    string result = "";
    for (int i = 0; i < n; i++) {
        if (!remove[i]) {
            result += s[i];
        }
    }

    return result;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "lee(t(c)o)de)";
  string ans = minRemoveToMakeValid(s);
  cout << ans << "\n";
}