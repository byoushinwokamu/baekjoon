#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int dddd[500000];
int cnt[8001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, sum = 0, max = -4000, min = 4000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dddd[i];
    sum += dddd[i];
    cnt[dddd[i] + 4000]++;
    max = max > dddd[i] ? max : dddd[i];
    min = min < dddd[i] ? min : dddd[i];
  }
  sort(dddd, dddd + n);
  cout << (int)round((double)sum / n) << '\n' << dddd[n / 2] << '\n';
  int cntmax = 0, c1 = -1, c2 = -1;
  for (int i = 0; i < 8001; i++) {
    if (cnt[i] > cntmax) {
      c1 = i;
      c2 = i;
      cntmax = cnt[i];
    } else if (cnt[i] == cntmax && c1 == c2) {
      c2 = i;
    }
  }
  cout << c2 - 4000 << '\n' << max - min;

  return 0;
}