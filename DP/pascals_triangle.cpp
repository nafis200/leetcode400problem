// Google (12) — Meta (4) — Amazon (4) — Bloomberg (4)


// Problem_Link: https://leetcode.com/problems/pascals-triangle/description/

#include<bits/stdc++.h>
using namespace std;

// time o (n ^2) auxilary space o(1)

   vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int row = 0; row < numRows; row++){
            vector<int>pascal(row + 1, 1);
            for(int col = 1; col < row; col++){
                 pascal[col] = ans[row - 1][col - 1] + ans[row - 1][col];
            }  
            ans.push_back(pascal);
        }
        return ans;
    }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int numsRows = 5;
     vector<vector<int>>ans = generate(numsRows);
     for(auto v : ans){
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
     }
}