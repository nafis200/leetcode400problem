// 6 months ago:
// Amazon (9) — J.P. Morgan (4) — Google (3) — IBM (2) — X (2)

// Problem_Link: https://www.lintcode.com/problem/1872/

#include <bits/stdc++.h>
using namespace std;

int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : sticks) {
        pq.push(x);
    }

    int totalCost = 0;

    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int cost = a + b;
        totalCost += cost;

        pq.push(cost);
    }

    return totalCost;
}