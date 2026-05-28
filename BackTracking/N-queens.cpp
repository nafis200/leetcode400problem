// 0 - 3 months:
// Google (13) — Amazon (7) — Microsoft (3) — Meta (2) — Bloomberg (2)

// 6 months ago:
// TikTok (18) — Goldman Sachs (7) — TCS (5) — Oracle (5) — Zoho (5) — IBM (2) — Adobe (2) — Apple (2) — Snowflake (2) — Salesforce (2)

// (0,0) (0,1) (0,2) (0,3)
// (1,0) (1,1) (1,2) (1,3)
// (2,0) (2,1) (2,2) (2,3)
// (3,0) (3,1) (3,2) (3,3)

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<int> col, diag1, diag2;

void solve(int row, int n, vector<string>& board) {

    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {

        if (col[c] || diag1[row - c + n] || diag2[row + c])
            continue;

        // place queen
        board[row][c] = 'Q';
        col[c] = 1;
        diag1[row - c + n] = 1;
        diag2[row + c] = 1;

        solve(row + 1, n, board);

        // backtrack
        board[row][c] = '.';
        col[c] = 0;
        diag1[row - c + n] = 0;
        diag2[row + c] = 0;
    }
}

int main() {

    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));

    col.assign(n, 0);
    diag1.assign(2 * n, 0);
    diag2.assign(2 * n, 0);

    solve(0, n, board);

    // print all solutions
    for (auto &solution : ans) {
        for (auto &row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}


