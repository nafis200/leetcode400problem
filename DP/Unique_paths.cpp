// 0 - 3 months:
// Meta (7) — Amazon (7) — Google (4) — Microsoft (3) — Bloomberg (2) — tcs (2)

// 0 - 6 months:
// LinkedIn (2)

// 6 months ago:
// Adobe (12) — Apple (8) — Uber (5) — Oracle (4) — Coupang (4) — Yahoo (4) — Goldman Sachs (3) — J.P. Morgan (2) — ByteDance (2) — TikTok (2)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>memo;

int x, y;

int dp(int i, int j){
    if(i >= x || j >= y){
        return 0;
    }
    if(i == x - 1 && j == y - 1){
        return 1;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = 0;
    ans = dp(i + 1, j) + dp(i, j + 1);
    return memo[i][j] = ans;
}

 int uniquePaths(int m, int n) {
    memo.assign(m, vector<int>(n, -1));
    x = m;
    y = n;
    int ans = dp(0, 0);
    return ans;
  }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = uniquePaths(3, 7);
    cout << ans << "\n";
}