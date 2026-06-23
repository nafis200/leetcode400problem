// 0 - 3 months:
// Google (12) — Amazon (3) — Microsoft (2) — LinkedIn (2) — TikTok (2)

// 0 - 6 months:
// Meta (7) — Visa (6) — Bloomberg (5) — Walmart Labs (2) — Capital One (2)

// 6 months ago:
// Uber (7) — DoorDash (7) — Flipkart (5) — Zoho (4) — Coupang (4) — Apple (3) —
// Goldman Sachs (3) — Myntra (3) — Roblox (3) — TCS (2)

// Problem_Link:
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

// Index:   0 1 2 3 4 5
// Height:  2 1 5 6 2 3

// Time o(n^2) space o(1)

// int largestRectangleArea(vector<int>& heights) {
//   int n = heights.size();
//   int ans = 0;
//   for (int i = 0; i < n; i++) {
//     int left = i;
//     int right = i;
//     for (int j = i - 1; j >= 0; j--) {
//       if (heights[j] < heights[i]) {
//         break;
//       }
//       left = j;
//     }

//     for (int j = i + 1; j < n; j++) {
//       if (heights[j] < heights[i]) {
//         break;
//       }
//       right = j;
//     }
    
//     int width = right - left + 1;
//     ans = max(ans, heights[i] * width);
//   }
//   return ans;
// }

// include 0
int largestRectangleArea(vector<int>& heights) {
   heights.push_back(0);
   int n = heights.size();
   stack<int>st;
   int ans = 0;
   for(int i = 0; i < n; i++){
      int curHeight = heights[i];
      while(!st.empty() && curHeight < heights[st.top()]){
          int calculateHeight = heights[st.top()];
          st.pop();
          int left = -1;
          if(!st.empty()){
             left = st.top();
          }
          int width = i - left - 1;
          int rectangle = width * calculateHeight;
          ans = max(ans, rectangle);
      }
      st.push(i);
   }
   return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> heights = {2, 1, 5, 6, 2, 3};

  int ans = largestRectangleArea(heights);
  cout << ans << "\n";
}