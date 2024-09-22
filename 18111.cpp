#include <iostream>

using namespace std;

int land[500][500];
int narashi[257]; // 해당 높이의 블록 개수
int brktim[257];  // 해당 층까지 부수는 시간
int filtim[257];  // 해당 층까지 채우는 시간

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m, b;
  cin >> n >> m >> b;
  int lowest = 257, highest = -1, siz = n * m;
  // 땅정보입력
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> land[i][j];
      for (int k = 0; k <= land[i][j]; k++)
        narashi[k]++;
      lowest = lowest < land[i][j] ? lowest : land[i][j];
      highest = highest > land[i][j] ? highest : land[i][j];
    }

  int range = highest - lowest;
  for (int i = 0; i <= range; i++) {
    filtim[lowest + i] =
        (i > 0 ? filtim[lowest + i - 1] : 0) + siz - narashi[lowest + i];
    brktim[highest - i] =
        (i > 1 ? brktim[highest - i + 1] : 0) + narashi[highest - i + 1] * 2;
  }
  int mintim = INT32_MAX;
  int minflo = 0;
  int tottim;
  for (int i = highest; i >= lowest; i--) {
    if (b + brktim[i] / 2 < filtim[i])
      continue;
    tottim = filtim[i] + brktim[i];
    if (tottim < mintim) {
      mintim = tottim;
      minflo = i;
    }
  }
  cout << mintim << " " << minflo;

  return 0;
}