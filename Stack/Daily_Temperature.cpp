// 0 - 3 months:
// Amazon (6) — Google (4) — Microsoft (2) — Agoda (2)

// 0 - 6 months:
// Bloomberg (5) — Verizon (3) — Meta (2) — Zoho (2) — Nvidia (2) — Swiggy (2) —
// Grab (2)

// 6 months ago:
// TikTok (12) — Apple (11) — Adobe (6) — Anduril (6) — Walmart Labs (5) — Yahoo
// (5) — Uber (4) — ServiceNow (4) — J.P. Morgan (3) — Goldman Sachs (3)

// Problem_Link: https://leetcode.com/problems/daily-temperatures/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n^2) space o(n)

// vector<int> dailyTemperatures(vector<int>& temperatures) {
//   vector<int> ans(temperatures.size(), 0);
//   int n = temperatures.size();
//   for (int i = n - 2; i >= 0; i--) {
//     for (int j = i + 1; j < n; j++) {
//       if (temperatures[j] > temperatures[i]) {
//         ans[i] = (j - i);
//         break;
//       }
//     }
//   }
//   return ans;
// }


// Time complexity o(n) space o(n)

vector<int> dailyTemperatures(vector<int>& temperatures) {
   stack<int>st;
   vector<int>ans(temperatures.size(), 0);

   int n = temperatures.size();

   for(int i = 0; i < n; i++){
      while(!st.empty() && temperatures[i] > temperatures[st.top()]){
           int idx = st.top();
           st.pop();
           ans[idx] = i - idx;
      }
      st.push(i);
   }
   return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
  temp = dailyTemperatures(temp);
  for (auto i : temp) {
    cout << i << " ";
  }
}