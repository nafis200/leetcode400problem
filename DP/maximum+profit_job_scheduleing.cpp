// 0 - 3 months:
// Airbnb (3) — Snowflake (2) — DoorDash (2) — Verkada (2)

// 0 - 6 months:
// Google (4) — Oracle (4) — Amazon (3) — Infosys (2) — Uber (2) — Meesho (2)

// 6 months ago:
// Pinterest (19) — Bloomberg (11) — Microsoft (9) — Goldman Sachs (6) — Meta
// (4) — PhonePe (4) — WeRide (4) — Flipkart (2) — ByteDance (2) — TikTok (2)

// Problem_Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int start;
    int end;
    int profit;
}a[50009];

static bool compare(const node &x,const node &y){
   if(x.end < y.end){
      return true;
   }
   return false;
}


int jobScheduling(vector<int>& startTime, vector<int>& endTime,vector<int>& profit) {
   
    int ans = 0;
    int n = startTime.size();
    for(int i = 0; i < n; i++){
        a[i + 1].start = startTime[i];
        a[i + 1].end = endTime[i];
        a[i + 1].profit = profit[i];
    }
    sort(a + 1, a + n + 1, compare);

    vector<int>pref(n + 1, 0);
    vector<int>dp(n + 1, 0);
  

    for(int i = 1; i <= n; i++){
        int l = 1;
        int h = i - 1;
        int j = 0;
        while(l <= h){
            int mid = (l + h) / 2;
            if(a[mid].end <= a[i].start){
               j = mid;
               l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        dp[i] = pref[j] + a[i].profit;
        pref[i] = max(pref[i - 1], dp[i]);
    }
    
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }

    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> startTime = {1, 2, 3, 3};
  vector<int> endTime =   {3, 4, 5, 6};
  vector<int> profit = {50, 10, 40, 70};
  int ans = jobScheduling(startTime, endTime, profit);
  cout << ans << "\n";
}