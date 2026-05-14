// 0 - 3 months:
// Amazon (14) — Microsoft (4) — TikTok (4) — Google (3) — Meta (3) — LinkedIn
// (3) — Nvidia (2) — DoorDash (2)

// 0 - 6 months:
// Uber (4) — Intuit (4) — Snowflake (3) — Salesforce (3) — Anduril (2) —
// Zenefits (2)

// 6 months ago:
// Apple (10) — Oracle (9) — Snap (7) — Tesla (5) — eBay (5) — Bloomberg (3) —
// ByteDance (3) — Walmart Labs (3) — Netflix (2) — Databricks (2)

// problem_Link: https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;
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
        vis[i] = true;
        z.push_back(i);
     }
  }
  while(ans.size() < numCourses && !z.empty()){
     int x = z.back();
     z.pop_back();
     ans.push_back(x);
     for(auto it : g[x]){
        indeg[it]--;
        if(indeg[it] == 0 && !vis[it]){
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
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int numCourses = 3;
  vector<vector<int>> pre = {{1,0},{1,2},{0,1}};

  vector<int> ans = findOrder(numCourses, pre);
  for (auto i : ans) {
    cout << i << " ";
  }
}