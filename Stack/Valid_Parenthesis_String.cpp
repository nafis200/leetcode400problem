// 0 - 3 months:
// Google (3) — Meta (3) — Motive (3) — PornHub (2)

// 0 - 6 months:
// TikTok (5) — Amazon (4) — Microsoft (2)

// 6 months ago:
// Bloomberg (8) — LinkedIn (4) — Apple (2) — Tekion (2) — Uber (2) — Palo Alto
// Networks (2) — Roku (2) — Alibaba (2)

// Problem_Link:
// https://leetcode.com/problems/valid-parenthesis-string/description/

#include <bits/stdc++.h>
using namespace std;

// * (
// give true but output false so position matter

// bool checkValidString(string s) {
//   stack<char> st, st1;
//   for (int i = 0; i < s.size(); i++) {
//     if (s[i] == '*') {
//       st1.push(s[i]);
//     }
//     else{
//         if(s[i] == '('){
//             st.push(s[i]);
//         }
//         else{
//             if(st.empty() && st1.empty()){
//                 return false;
//             }
//             else if(st.empty() && !st1.empty()){
//                 st1.pop();
//             }
//             else if(!st.empty() && st1.empty()){
//                 st.pop();
//             }
//             else{
//                 st.pop();
//             }
//         }
//     }
//   }
//   if(st.size() <= st1.size()){
//     return true;
//   }
//   return false;
// }


bool checkValidString(string s) {
  stack<int> open, star;
  int n = s.size();
  for(int i = 0; i < n; i++){
     if(s[i] == '('){
         open.push(i);
     }
     else if(s[i] == '*'){
          star.push(i);
     }
     else{
        if(!open.empty()){
            open.pop();
        }
        else if(!star.empty()){
            star.pop();
        }
        else{
            return false;
        }
     }
  }
  while(!open.empty() && !star.empty()){
     if(open.top() > star.top()){
        return false;
     }
     open.pop();
     star.pop();
  }
  return open.size() <= star.size();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}