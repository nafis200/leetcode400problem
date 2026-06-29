// 0 - 3 months:
// Google (7) — Meta (7) — Amazon (6) — Microsoft (5) — Uber (3) — Apple (2) — Oracle (2) — TikTok (2) — Cloudflare (2) — Salesforce (2)

// 0 - 6 months:
// Roblox (5) — Bloomberg (3) — ByteDance (3) — LinkedIn (2) — Nvidia (2) — Anduril (2)

// 6 months ago:
// Coupang (7) — Snowflake (6) — Nordstrom (4) — Visa (4) — eBay (4) — Adobe (3) — Flipkart (3) — Swiggy (3) — DoorDash (3) — Snap (3)

// Problem_Link: https://leetcode.com/problems/course-schedule/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);

    for (auto v : prerequisites) {

        int u = v[0];
        int y = v[1];

        adj[y].push_back(u); 
        indeg[u]++;
    }

    vector<int> ans, z;

    for (int i = 0; i < numCourses; i++) {

        if (indeg[i] == 0) {

            z.push_back(i);
        }
    }

    while (!z.empty()) {

        int x = z.back();
        z.pop_back();

        ans.push_back(x);

        for (auto it : adj[x]) {

            indeg[it]--;

            if (indeg[it] == 0) {

                z.push_back(it);
            }
        }
    }

    if(ans.size() == numCourses){
         return true;
    }
    return false;
}
};