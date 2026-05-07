// 0 - 3 months:
// Google (3) — Amazon (3) — Infosys (2) — Apple (2) — Goldman Sachs (2)

// 0 - 6 months:
// CME Group (7) — Microsoft (4) — Accolite (4) — Meta (3) — Bloomberg (3) —
// Visa (3)

// 6 months ago:
// Flipkart (7) — Oracle (6) — BitGo (6) — TikTok (4) — Adobe (3) — Juspay (3) —
// Zoho (3) — Cisco (3) — Salesforce (3) — PhonePe

#include <bits/stdc++.h>
using namespace std;

// space o(1) time o(n^2)

// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n = gas.size();

//     for (int i = 0; i < n; i++) {
//         int total = gas[i];
//         bool ok = true;

//         for (int j = i; j < i + n; j++) {
//             int current = j % n;
//             total -= cost[current];

//             if (total < 0) {
//                 ok = false;
//                 break;
//             }

//             int next = (j + 1) % n;
//             total += gas[next];
//         }

//         if (ok) {
//             return i;
//         }
//     }

//     return -1;
// }

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int total_gas = 0;
  int total_cost = 0;

  for (int i = 0; i < (int)gas.size(); i++) {
    total_gas += gas[i];
    total_cost += cost[i];
  }
  if (total_gas < total_cost) {
    return -1;
  }

  int start_point = 0;
  int current_cost = 0;
  for (int i = 0; i < gas.size(); i++) {
    current_cost += (gas[i] - cost[i]);
    if (current_cost < 0) {
      start_point = i + 1;
      current_cost = 0;
    }
  }
  return start_point;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};

  int ans = canCompleteCircuit(gas, cost);

  cout << ans << "\n";

  return 0;
}