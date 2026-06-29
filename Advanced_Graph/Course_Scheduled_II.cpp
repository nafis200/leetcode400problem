// 0 - 3 months:
// Google (7) — Snowflake (5) — Microsoft (3) — LinkedIn (3) — Apple (3) — Anduril (3) — Meta (2) — Netflix (2) — Moloco (2)

// 0 - 6 months:
// Roblox (11) — Amazon (5) — Bloomberg (4) — Oracle (3) — TikTok (2) — Goldman Sachs (2) — Uber (2) — Arista Networks (2) — Citadel (2) — Snap (2)

// 6 months ago:
// DoorDash (11) — Intuit (10) — Salesforce (8) — Walmart Labs (4) — IBM (3) — Nvidia (3) — Flipkart (2) — Qualcomm (2) — Palantir Technologies (2) — Nutanix (2)

// Problem_Link: https://leetcode.com/problems/course-schedule-ii/submissions/2050096010/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<bool> vis(numCourses, false);
  vector<int> indeg(numCourses, 0);
  vector<vector<int>> g(numCourses);
  vector<int> order;
 
  for (auto ve : prerequisites) {
    int u = ve[0];
    int v = ve[1];
    indeg[u]++;
    g[v].push_back(u);
  
  }
  vector<int>ans,z;
  for(int i = 0; i < numCourses; i++){
     if(indeg[i] == 0){
        z.push_back(i);
     }
  }
  while(!z.empty()){
     int x = z.back();
     z.pop_back();
     ans.push_back(x);
     for(auto it : g[x]){
        indeg[it]--;
        if(indeg[it] == 0){
            vis[it] = true;
            z.push_back(it);
        }
     }
  }
  
  for(auto it : ans){
    order.push_back(it);
  }
  if(ans.size() == numCourses)
  return order;

  return {};
}
};