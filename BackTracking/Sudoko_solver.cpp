// 0 - 3 months:
// Google (8) — Bloomberg (3) — Amazon (2) — eBay (2)

// 0 - 6 months:
// Confluent (4) — Meta (3)

// 6 months ago:
// Microsoft (32) — Intuit (7) — Uber (5) — DoorDash (4) — Zoho (3) — Citadel (3) — Riot Games (3) — Adobe (2) — Goldman Sachs (2) — Snap (2)

#include<bits/stdc++.h>
using namespace std;

// time complexity 9^w (w means empty space)
//  9^81

bool isValid(vector<vector<char>>& board, int row, int col, char ch){
   int startRow = row / 3 * 3;
   int startCol = col / 3 * 3;
   for(int i = 0; i < 9; i++){
     if(board[row][i] == ch){
        return false;
     }
     if(board[i][col] == ch){
        return false;
     }
   }

   for(int i = 0; i < 3; i++){
     for(int j = 0; j < 3; j++){
        if(board[startRow + i][startCol + j] == ch){
            return false;
        }
     }
   }
   return true;

}

bool solve(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.'){
                for(char ch = '1'; ch <= '9'; ch++){
                    if(isValid(board, i, j, ch)){
                        board[i][j] = ch;
                        if(solve(board)){
                           return true; 
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

  void solveSudoku(vector<vector<char>>& board) {
     solve(board);      
  }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solve(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}