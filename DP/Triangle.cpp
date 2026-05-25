// 0 - 3 months:
// Bloomberg (3) — Amazon (2)

// 0 - 6 months:
// Google (6) — Meta (2) — Microsoft (2)

// 6 months ago:
// Oracle (3) — Apple (2) — Walmart Labs (2) — Goldman Sachs (2) — Agoda (2) —
// Upstart (2)

// Problem_Link: https://leetcode.com/problems/triangle/

//        2
//     3     4
//   6    5    7
// 4   1  8      3

#include <bits/stdc++.h>
using namespace std;

// time o(n ^ 2) space o(n ^ 2)

//  int minimumTotal(vector<vector<int>>& triangle) {
//     int n = triangle.size();
//     int m = triangle[0].size();
//     vector<vector<int>>memo;
//     memo.assign(n + 1, vector<int>(n + 1, INT_MAX));
//     memo[0][0] = triangle[0][0];
//     for(int i = 1; i < n; i++){
//         for(int j = 0; j <= i; j++){
//           if(j == 0){
//              memo[i][j] = memo[i - 1][j] + triangle[i][j];
//           }
//           else if(j == i){
//             memo[i][j] = memo[i - 1][j - 1] + triangle[i][j];
//           }
//           else{
//             //  2 , 1   ---->   1, 0 |  1, 1
//              int min1 = memo[i - 1][j - 1] + triangle[i][j];
//              int min2 = memo[i - 1][j] + triangle[i][j];
//              memo[i][j] = min(min1, min2);
//           }
//         }
//     }       
//     int ans = INT_MAX;
//     for(int i = 0; i < n; i++){
//         ans = min(ans, memo[n - 1][i]);
//     }
//     return ans;
//  }

//        2
//     3     4
//   6    5    7
// 4   1  8      3

//  2
//  5  6
//  11  10 13
//  15  11   18  16

// space o(n)

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[0].size();
    vector<int>memo(n + 1, 0);
    memo[0] = triangle[0][0];
    for(int i = 1; i < n; i++){
        for(int j = i; j >= 0 ; j--){
            if(j == 0){
                memo[j] = memo[j] + triangle[i][j];
            }
            else if(j == i){
                memo[j] = memo[j - 1] + triangle[i][j];
            }
            else{
                int min1 = memo[j] + triangle[i][j];
                int min2 = memo[j - 1] + triangle[i][j];
                memo[j] = min(min1, min2);
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, memo[i]);
    }
    return ans;
 }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int ans = minimumTotal(triangle);
  cout << ans << "\n";

}
