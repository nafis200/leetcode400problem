// 0 - 3 months:
// Amazon (3)

// 0 - 6 months:
// Microsoft (3) — Meta (2)

// 6 months ago:
// Google (18) — Bloomberg (5) — BNY Mellon (3) — Infosys (2) — Nutanix (2) — GE
// Healthcare (2)

// Problem_Link: https://leetcode.com/problems/car-fleet/description/

// target = 12
// position = [10,8,0,5,3]
// speed    = [2,4,1,1,3]

// (0,12), (3,3), (5,7), (8,1), (10,1)

#include <bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, double>> v;

    int n = speed.size();

    for (int i = 0; i < n; i++) {
        double time = (double)(target - position[i]) / speed[i];
        v.push_back({position[i], time});
    }

    sort(v.begin(), v.end());

    int fleet = 0;
    double maxTime = 0;

    for (int i = n - 1; i >= 0; i--) {
        double time = v[i].second;

        if (time > maxTime) {
            maxTime = time;
            fleet++;
        }
    }

    return fleet;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}