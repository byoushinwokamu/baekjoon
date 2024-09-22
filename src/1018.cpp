#include <iostream>

using namespace std;

char board[50][51];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> board[i];

  int cnt = 0;
  int mincnt = 64;
  for (int k1 = 0; k1 <= n - 8; k1++) {
    for (int k2 = 0; k2 <= m - 8; k2++) {
      cnt = 0;
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          char cell = (i + j) % 2 * 21 + 'B';
          if (cell == board[k1 + i][k2 + j])
            cnt++;
        }
      }
      cnt = (32 > cnt ? cnt : (64 - cnt));
      mincnt = mincnt < cnt ? mincnt : cnt;
    }
  }
  cout << mincnt;

  return 0;
}