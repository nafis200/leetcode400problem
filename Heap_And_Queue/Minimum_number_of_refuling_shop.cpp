// 0 - 3 months:
// Google (2) — Waymo (2)

// 0 - 6 months:
// Microsoft (2) — Amazon (2)

// 6 months ago:
// DE Shaw (5) — Bloomberg (4) — Meta (2) — Goldman Sachs (2)

// Problem_Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
     
    sort(stations.begin(),stations.end());
    int i = 0;
    int stops = 0;
    int reach = startFuel;
    priority_queue<int>pq;
    while(reach < target){
        while(i < stations.size() && stations[i][0] <= reach){
             pq.push(stations[i][1]);
             i++;
        }
        if(pq.empty()){
            return -1;
        }
        reach += pq.top();
        pq.pop();
        stops++;
    }
    return stops;

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}