// 0 - 3 months:
// Amazon (6) — Google (3)

// 0 - 6 months:
// Apple (3) — Meta (2) — Microsoft (2) — Oracle (2) — Uber (2)

// 6 months ago:
// Adobe (6) — Bloomberg (3) — tcs (2) — Snap (2) — Coupang (2)

// Problem_Link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      int m = matrix[0].size();
      
      for(int i = 0; i < n; i++){
          int l = 0, r = m - 1, mid = 0;
          while(l <= r){
             mid = l + (r - l) / 2;
             if(matrix[i][mid] == target){
                return true;
             }
             else if(matrix[i][mid] < target){
                l = mid + 1;
             }
             else{
                r = mid - 1;
             }
          }
      }
      return false;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 5;

    bool ans = searchMatrix(matrix, target);

    cout << ans << "\n";

    return 0;
}