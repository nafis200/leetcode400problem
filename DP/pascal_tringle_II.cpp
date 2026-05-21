 
// 0 - 3 months: Google (3)
// 0 - 6 months: Amazon (3)
// 6 months ago: Bloomberg (5) — Goldman Sachs (4) — Meta (3) — Yahoo (3) — Microsoft (2) — Adobe (2) — Apple (2)

// problem_Link: https://leetcode.com/problems/pascals-triangle-ii/description/

#include<bits/stdc++.h>
using namespace std;

   vector<int> getRow(int numRows) {
        vector<int>rows(numRows + 1, 1);
        for(int i = 2; i <= numRows; i++){
            for(int j = i - 1; j >= 1; j--){
                rows[j] = rows[j] + rows[j - 1];
            }
        }
        return rows;
    }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int numsRows = 3;
     vector<int>ans = getRow(numsRows);
     for(auto v : ans){
        cout << v << " ";
     }
}