// 0 - 3 months:
// Google (6) — Amazon (3) — Meta (2) — Ericsson (2)

// 0 - 6 months:
// Squarepoint Capital (4) — Microsoft (3) — Uber (2) — Boeing (2) — Rokt (2)

// 6 months ago:
// Bloomberg (11) — TikTok (8) — Snowflake (7) — DoorDash (7) — Apple (3) — Snap
// (3) — Canva (3) — Adobe (2) — Oracle (2) — ByteDance (2)

// Problem_Link: https://leetcode.com/problems/basic-calculator/description/

#include <bits/stdc++.h>
using namespace std;
int calculate(string s) {
  int result = 0;
  int sign = +1;
  stack<int> preResult;
  stack<int> prevsign;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (isdigit(s[i])) {
      long long num = 0;
      while (i < n && isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
        i++;
      }
      result += sign * num;
      i--;
    } else if (s[i] == '+') {
      sign = 1;
    } else if (s[i] == '-') {
      sign = -1;
    } else if (s[i] == '(') {
      preResult.push(result);
      prevsign.push(sign);
      result = 0;
      sign = 1;
    } else if (s[i] == ')') {
      int res = preResult.top();
      int sig = prevsign.top();
      result = res + sig * result;
      preResult.pop();
      prevsign.pop();
    }
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s = "(1+(4+5+2)-3)+(6+8)";
  cout << calculate(s) << "\n";
}