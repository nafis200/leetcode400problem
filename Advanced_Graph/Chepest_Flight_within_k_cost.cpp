// 0 - 3 months:
// HTC (10) — Google (3) — Microsoft (2) — Amazon (2) — Uber (2)

// 6 months ago:
// Meta (10) — MakeMyTrip (5) — Stripe (5) — Airbnb (4) — Bloomberg (3) — Apple
// (3) — Flipkart (3) — DE Shaw (2) — Snowflake (2) — Snap (2)

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// dist 0 INF INF
// tmp  0 INF INF

// first relaxtion

//  dist 0 100 INF
//  tmp  0 INF INF

// so 2nd value not update okay and right


#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                      int k) {
  vector<int> dist(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;
  for (int i = 0; i <= k; i++) {
    vector<int> temp = dist;
    for (auto filght : flights) {
      int a = filght[0];
      int b = filght[1];
      int c = filght[2];
      if (temp[a] != INT_MAX && temp[a] + c < dist[b]) {
        dist[b] = temp[a] + c;
      }
    }
  }
  if(dist[dst] == INT_MAX){
     return -1;
  }
  return dist[dst];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}