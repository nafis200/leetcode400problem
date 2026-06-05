// 0 - 3 months:
// Apple (3) — Google (2) — Microsoft (2) — Amazon (2) — Uber (2)

// 0 - 6 months:
// Meta (2) — Bloomberg (2) — Tesco (2)

// 6 months ago:
// Adobe (6) — Oracle (4) — TikTok (4) — MongoDB (4) — Walmart Labs (3) — LinkedIn (2) — Synology (2) — Blend (2) — Yahoo (2)

// Problem_Link: https://leetcode.com/problems/insert-interval/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

//  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
//     vector<vector<int>>ans;
//     intervals.push_back(newInterval);
//     sort(intervals.begin(), intervals.end());
//     ans.push_back(intervals[0]);

//     for(int i = 1; i < intervals.size(); i++){
//          if(ans.back()[1] < intervals[i][0]){
//             ans.push_back(intervals[i]);
//          }
//          else{
//             ans.back()[1] = max(ans.back()[1], intervals[i][1]);
//          }
//     }
//     return ans;
//  }

// Time o(n) space o(1)

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    vector<vector<int>>ans;
    int i = 0;
    int n = intervals.size();

    while(i < n && intervals[i][1] < newInterval[0]){
         ans.push_back(intervals[i]);
         i++;
    }

    // overlapping
  
     while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
     }

     ans.push_back(newInterval);

    // 
   
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }
  return ans;
    
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> intervals = {
    {1, 2},
    {3, 5},
    {6, 7},
    {8, 10},
    {12, 16}
};

vector<int> newInterval = {4, 8};
}