// 0 - 3 months:
// Amazon (28) — Google (14) — Meta (10) — Bloomberg (4) — Apple (4) — Microsoft
// (3) — TikTok (2) — Anduril (2) — Snowflake (2) — Coupang (2)

// 0 - 6 months:
// Uber (4) — Visa (3) — ByteDance (2) — Citadel (2) — Yelp (2) — LiveRamp (2) —
// Graviton (2) — Zenefits (2)

// 6 months ago:
// Adobe (12) — Oracle (6) — Flipkart (5) — Karat (5) — Snap (4) — Yahoo (4) —
// VMware (3) — Nutanix (3) — Walmart Labs (2) — Intuit (2)

// problem_Link: https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);
    vector<bool> visited(numCourses, false);

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
            visited[i] = true;
        }
    }

    while (!z.empty()) {

        int x = z.back();
        z.pop_back();

        ans.push_back(x);

        for (auto it : adj[x]) {

            indeg[it]--;

            if (indeg[it] == 0 && !visited[it]) {

                z.push_back(it);
                visited[it] = true;
            }
        }
    }

    if(ans.size() == numCourses){
         return true;
    }
    return false;
}

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numCourse = 2;

    vector<vector<int>> prerequisites = {{1, 0}};

    bool ans = canFinish(numCourse, prerequisites);

    cout << ans << "\n";
}