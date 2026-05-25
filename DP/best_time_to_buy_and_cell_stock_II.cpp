// 0 - 3 months:
// Meta (3) — Google (2)

// 0 - 6 months:
// Microsoft (2) — TikTok (2)

// 6 months ago:
// Amazon (14) — Bloomberg (4) — Snap (4) — Apple (3) — Tekion (3) — Adobe (2) — Goldman Sachs (2) — Citadel (2) — Bolt (2)

// Problem_Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/2011645225/


#include <bits/stdc++.h>
using namespace std;

// buy --> sell --> buy --> sell

int maxProfit(vector<int>& prices) {

    int buy1 = INT_MIN;
    int sell1 = 0;

    int buy2 = INT_MIN;
    int sell2 = 0;

    for (int p : prices) {

        buy1 = max(buy1, -p);

        sell1 = max(sell1, buy1 + p);

        buy2 = max(buy2, sell1 - p);

        sell2 = max(sell2, buy2 + p);
    }

    return sell2;
}

int main() {

    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << maxProfit(prices) << endl;

    return 0;
}