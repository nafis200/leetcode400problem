// 0 - 3 months:
// Google (6) — Amazon (6) — Microsoft (5) — Meta (3) — Bloomberg (3)

// 6 months ago:
// Oracle (8) — TikTok (5) — Adobe (4) — Goldman Sachs (4) — Apple (3) — Walmart Labs (3) — Nutanix (3) — Tinkoff (2) — Arista Networks (2) — Accenture (2)

// Problem_Link: https://leetcode.com/problems/search-a-2d-matrix/description/

#include<bits/stdc++.h>
using namespace std;
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
 
//     int n = matrix.size();
//     int m = matrix[0].size();
//     bool ans = false;
    
//     int row = n - 1, col = 0;
//     while(row >= 0 && col < m){
//         if(matrix[row][col] == target){
//             ans = true;
//             break;
//         }
//         else if(matrix[row][col] < target){
//             col++;
//         }
//         else{
//             row--;
//         }
//     }
//   return ans;
// }


// Seem 1D Array

// 1  3  5  7
// 10 11 16 20
// 23 30 34 60

// Time o(log(n * m)) space o(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {
 
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0, r = n * m - 1, mid = 0, ans = 0;

    while(l <= r){
        mid = l + (r - l) / 2;
        int row = mid / m;
        int col = mid % m;
        if(matrix[row][col] == target){
            ans = 1;
            break;
        }
        else if(matrix[row][col] > target){
            r = mid - 1;
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
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
};

int target = 3;

bool ans = searchMatrix(matrix, target);

cout << ans << "\n";

}