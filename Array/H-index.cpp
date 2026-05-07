// 0 - 3 months:
// Amazon (3) — Microsoft (2)

// 0 - 6 months:
// Bloomberg (2)

// 6 months ago:
// Google (21) — Apple (4) — Meta (3) — LinkedIn (3) — Nvidia (2)

// 6 5 3 1 0
//  h = 1  >= 4
//  h = 2  >= 3
//  h = 3  >= 3
//  h = 4  >= 2
//  h = 5  >= 1

// time nlogn space o(1)

#include <bits/stdc++.h>
using namespace std;
// int hIndex(vector<int>& citations) {
//     sort(citations.begin(),citations.end());
//     reverse(citations.begin(),citations.end());

//     int n = citations.size();

//     int mx = 0;

//     for(int i = 0; i < n; i++){
//         if(i + 1 <= citations[i]){
//             mx = i + 1;
//         }
//     }
//     return mx;
// }

// time o(n) space o(n)

int hIndex(vector<int>& citations) {
  int n = citations.size();

  vector<int> counts(n + 1, 0);

  for (auto it : citations) {
    if (it > n) {
      counts[n]++;
    } else {
      counts[it]++;
    }
  }
  int papers = 0;

  for (int i = n; i >= 0; i--) {
    papers += counts[i];
    if (papers >= i) {
      return i;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> citation = {3, 1, 0, 6, 5};

  int ans = hIndex(citation);
  cout << ans << "\n";
}