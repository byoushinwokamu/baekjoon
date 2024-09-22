#include <iostream>

using namespace std;
typedef long long ll;
ll paint[50];
char line[8];
int n, minn = 40, aa, bb;

int compare(int a, int b) {
  ll p = paint[a] ^ paint[b];
  int res = 0;
  for (int i = 0; i < 35; i++) {
    if (p & 1)
      res++;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> line;
      for (int k = 0; k < 7; k++) {
        paint[i] |= (line[k] == 'X' ? (ll)1 : (ll)0) << (j * 7 + k);
      }
    }
  }
  int c;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      c = compare(i, j);
      if (c < minn)
        minn = c, aa = i, bb = j;
    }
  }
  cout << aa + 1 << ' ' << bb + 1;

  return 0;
}