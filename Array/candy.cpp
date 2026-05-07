// 0 - 3 months:
// Amazon (8) — Google (6) — Meta (3) — Microsoft (2) — Dropbox (2)

// 0 - 6 months:
// Bloomberg (2)

// 6 months ago:
// Uber (6) — PhonePe (5) — Flipkart (4) — Oracle (3) — TikTok (3) — Goldman
// Sachs (3) — IBM (2) — Morgan Stanley (2) — DE Shaw (2) — Accenture (2)

// problem link: https://leetcode.com/problems/candy/description/

// time complexity o(n^2) space o(n)

#include <bits/stdc++.h>
using namespace std;

// int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> candies(n, 1);
//         bool has_changed = true;

//         while (has_changed) {
//             has_changed = false;
//             for (int i = 0; i < n; i++) {
//                 if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
//                     candies[i] = candies[i - 1] + 1;
//                     has_changed = true;
//                 }
//                 if (i < n - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
//                     candies[i] = candies[i + 1] + 1;
//                     has_changed = true;
//                 }
//             }
//         }

//         int total_candies = 0;
//         for (int c : candies) {
//             total_candies += c;
//         }
//         return total_candies;
//   }


// Two pass Algorithm

// time o(n) space o(n)

int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int total_candies = 0;
        for (int c : candies) {
            total_candies += c;
        }
        return total_candies;
    }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> rating;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    rating.push_back(x);
  }

  int ans = candy(rating);

  for (auto it : rating) {
    cout << it << " ";
  }
}