#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  vector<vector<int>> board(5, vector<int>(5));
  int n;

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> board[i][j];

  for (int t = 0; t < 25; t++) {
    cin >> n;

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (board[i][j] == n)
          board[i][j] = 0;
      }
    }

    int l = 0;
    // horizontal
    for (int i = 0; i < 5; i++) {
      int c = 5;
      for (int j = 0; j < 5; j++) {
        board[i][j] ? c : c--;
      }
      c ? l : l++;
    }

    // vertical
    for (int i = 0; i < 5; i++) {
      int c = 5;
      for (int j = 0; j < 5; j++) {
        board[j][i] ? c : c--;
      }
      c ? l : l++;
    }

    // diagonal
    int c1 = 5, c2 = 5;
    for (int i = 0; i < 5; i++) {
      board[i][i] ? c1 : c1--;
      board[i][4 - i] ? c2 : c2--;
    }
    c1 ? l : l++;
    c2 ? l : l++;

    if (l > 2) {
      cout << t + 1;
      return 0;
    }
  }
  return 0;
}