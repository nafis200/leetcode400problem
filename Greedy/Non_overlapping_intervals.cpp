// 0 - 3 months:
// Amazon (4) — Bloomberg (4) — Verkada (3) — Google (2) — Grammarly (2)

// 0 - 6 months:
// Meta (2) — IBM (2) — Zoho (2)

// 6 months ago:
// Microsoft (11) — TikTok (3) — J.P. Morgan (2) — Oracle (2) — Goldman Sachs
// (2) — Snowflake (2) — Capital One (2)

// Problem_Link:
// https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(vector<int>a, vector<int>b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
         if(a[1] < b[1]){
            return true;
         }
         return false;
    }
};

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp());
    int remove = 0;
    int end = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] < end){
            remove++;
        }
        else{
            end = intervals[i][1];
        }
    }
    return remove;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  int ans = eraseOverlapIntervals(intervals);

  cout << ans << "\n";
}