// 0 - 3 months: IBM (3)
// 0 - 6 months: Google (4)
// 6 months ago: Amazon (7) — Microsoft (2) — Uber (2)

// problem link: https://leetcode.com/problems/flipping-an-image/description/

// solution first

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> InvertImage(vector<vector<int>>& image) {
  int rows = image.size();
  int cols = image[0].size();
  for (int i = 0; i < rows; i++) {
    int j = 0, k = cols - 1;
    while (j < k) {
      swap(image[i][j], image[i][k]);
      j++;
      k--;
    }
  }
  return image;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
  auto it = InvertImage(image);
  int rows = image.size();
  int cols = image[0].size();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      image[i][j] ^= 1;
    }
  }
  return image;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

  auto it = flipAndInvertImage(image);

  int rows = image.size();
  int cols = image[0].size();

  for (int i = 0; i < rows; i++) {
    cout << "[";
    for (int j = 0; j < cols; j++) {
      cout << image[i][j] << " ";
    }
    cout << "]";
  }
}

// time complexity o(n^2)
// auxilary space complexity o(1);