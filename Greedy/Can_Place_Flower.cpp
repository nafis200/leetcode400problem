 
 	
// 0 - 3 months: Meta (5) — Google (3) — Microsoft (3) — Amazon (3) — Bloomberg (2) — LinkedIn (2)
// 0 - 6 months: Nike (2)
// 6 months ago: Adobe (7) — Apple (6) — Yahoo (4) — Uber (3) — Yandex (3) — IBM (2) — Jio (2)

// Problem_Link: https://leetcode.com/problems/can-place-flowers/description/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int cnt = 0;
    int m = flowerbed.size();

    for (int i = 0; i < m; i++) {
        if (flowerbed[i] == 0) {
            bool left = (i == 0 || flowerbed[i - 1] == 0);
            bool right = (i == m - 1 || flowerbed[i + 1] == 0);

            if (left && right) {
                flowerbed[i] = 1; 
                cnt++;
            }
        }
    }

    return cnt >= n;
}

int main() {
    int m, n;
    cin >> m;

    vector<int> flowerbed(m);
    for (int i = 0; i < m; i++) {
        cin >> flowerbed[i];
    }

    cin >> n;

    if (canPlaceFlowers(flowerbed, n))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}