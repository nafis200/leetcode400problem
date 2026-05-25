// 6 months ago:
// Google (15) — Amazon (8) — Microsoft (7) — Apple (4) — TikTok (4) — Meta (3) — Goldman Sachs (3) — DE Shaw (2) — Nielsen (2)

// Problem_Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(int k, vector<int>& prices) {

    vector<int> buy(k + 1, INT_MIN);
    vector<int> sell(k + 1, 0);

    for (int p : prices) {

        for (int t = 1; t <= k; t++) {

            buy[t] = max(
                buy[t],
                sell[t - 1] - p
            );

            sell[t] = max(
                sell[t],
                buy[t] + p
            );
        }
    }

    return sell[k];
}

int main() {

    int k = 2;
    vector<int> prices = {1,2,3};

    cout << maxProfit(k, prices);

    return 0;
}