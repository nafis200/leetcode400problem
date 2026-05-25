// 0 - 3 months:
// Apple (3) — Bloomberg (2) — AQR Capital Management (2)

// 0 - 6 months:
// Google (5) — Amazon (2)

// 6 months ago:
// Geico (5) — TikTok (3) — Microsoft (2) — Goldman Sachs (2)

// Problem_Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

    int buy = INT_MIN;
    int cool = 0;
    int sell = 0;

    for (int p : prices) {

        int prevBuy = buy;
        int prevCool = cool;
        int prevSell = sell;

     
        buy = max(
            prevBuy,
            prevSell - p
        );

        cool = prevBuy + p;


        sell = max(
            prevSell,
            prevCool
        );
    }

    return max(sell, cool);
}

int main() {

    vector<int> prices = {1,2,3,0,2};

    cout << maxProfit(prices);

    return 0;
}