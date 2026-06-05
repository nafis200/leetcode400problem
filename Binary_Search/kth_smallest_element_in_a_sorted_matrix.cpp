// 0 - 3 months:
// Meta (8) — Amazon (4) — Apple (2)

// 0 - 6 months:
// Google (3) — TikTok (3) — X (2)

// 6 months ago:
// Microsoft (6) — Bloomberg (3) — Oracle (3) — Salesforce (3) — Uber (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n * m) space o(n * m)

// int kthSmallest(vector<vector<int>>& matrix, int k) {
//      int n = matrix.size();
//      int m = matrix[0].size();
//      vector<int>ans;
//      for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             int value = matrix[i][j];
//             ans.push_back(value);
//         }
//      }        
//      sort(ans.begin(),ans.end());
//      return ans[k - 1];
// }


// time n log(Max Element of Array)

//  1   5   9
//  10  11  13
//  12  13  15

int countKth(vector<vector<int>>& matrix, int k){
    int n = matrix.size();
    int row = n - 1, col = 0;
    int count = 0;
    while(row >= 0 && col < n){
        if(matrix[row][col] <= k){
          count += (row + 1);
          col++;
        }
        else{
            row--;
        }
    }
    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
     int l = matrix[0][0];
     int n = matrix.size();
     int h = matrix[n - 1][n - 1];

     int ans = 0;
     while(l <= h){
        int mid = l + (h - l) / 2;
        if(countKth(matrix, mid) >= k){
            ans = mid;
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }

     }
     return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> matrix = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    int ans = kthSmallest(matrix, k);
    cout << ans << "\n";

}