// Amazon (9) — Microsoft (2)
// 0 - 6 months: Google (3) — Meta (2) — Bloomberg (2) — Goldman Sachs (2) —
// Uber (2) 6 months ago: Apple (10) — Adobe (3) — Yahoo (3) — Akuna Capital (2)
// — Palantir Technologies (2) — Sumo Logic (2)

// problem_Link: https://leetcode.com/problems/flood-fill/description/

// #include <bits/stdc++.h>
// using namespace std;

// time o(n * m) space o(n * m)

// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};

// bool isValid(vector<vector<int>>& image, int sr, int sc,
//              vector<vector<bool>>& visited, int original) {
//   int row = image.size();
//   int col = image[0].size();
//   if (sr >= 0 && sr <= row - 1 && sc >= 0 && sc <= col - 1 &&
//       visited[sr][sc] == false && image[sr][sc] == original) {
//     return true;
//   }
//   return false;
// }

// void DFS(vector<vector<int>>& image, int sr, int sc, int color,
//          vector<vector<bool>>& visited, int original) {
//   visited[sr][sc] = true;
//   image[sr][sc] = color;
//   for (int k = 0; k < 4; k++) {
//     int next_i = sr + dx[k];
//     int next_j = sc + dy[k];
//     if (isValid(image, next_i, next_j, visited, original)) {
//       DFS(image, next_i, next_j, color, visited, original);
//     }
//   }
// }

// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
//                               int color) {
//   vector<vector<bool>> visited(image.size(),
//                                vector<bool>(image[0].size(), false));
   
//   int original = image[sr][sc];
//   DFS(image, sr, sc, color, visited, original);
//   return image;
// }


#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(vector<vector<int>>& image, int i, int j, int original) {
    int row = image.size();
    int col = image[0].size();

    return (i >= 0 && i < row &&
            j >= 0 && j < col &&
            image[i][j] == original);
}

void DFS(vector<vector<int>>& image,
         int sr,
         int sc,
         int color,
         int original) {

    image[sr][sc] = color;

    for (int k = 0; k < 4; k++) {

        int next_i = sr + dx[k];
        int next_j = sc + dy[k];

        if (isValid(image, next_i, next_j, original)) {
            DFS(image, next_i, next_j, color, original);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image,
                              int sr,
                              int sc,
                              int color) {

    int original = image[sr][sc];

    if (original == color) return image;

    DFS(image, sr, sc, color, original);

    return image;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

  int sr = 1, sc = 1, color = 2;

  floodFill(image, sr, sc, color);

  for (auto v : image) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }
}