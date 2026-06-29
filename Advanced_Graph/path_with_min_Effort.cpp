
// 0 - 3 months:
// Google (2)

// 0 - 6 months:
// Meta (2)

// 6 months ago:
// Amazon (7) — Microsoft (4) — Bloomberg (4) — TikTok (2) — Snowflake (2) — Nutanix (2)

// Problem_Link: https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int effort = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if(x == n-1 && y == m-1)
                return effort;

            if(effort > dist[x][y])
                continue;

            for(int i=0;i<4;i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){

                    int edge = abs(heights[x][y]-heights[nx][ny]);

                    int newEffort = max(effort, edge);

                    if(newEffort < dist[nx][ny]){

                        dist[nx][ny] = newEffort;

                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }

        return 0;
    }
};