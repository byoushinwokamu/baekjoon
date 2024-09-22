#include <iostream>

using namespace std;

int n, nn, cnt, qb;
int qq[16];
int ver[16];

bool check(const int p1, const int p2) {
  const int x = p1 % n - p2 % n;
  const int y = p1 / n - p2 / n;
  if (x == y || x == -y)
    return false;
  return true;
}

void solve(const int q) {
  int p = (qq[q - 1] / n + 1) * n;

  for (int i = 0; i < n; i++) {
    bool doit = true;
    if (ver[i])
      continue;
    for (int j = 0; j < q; j++) {
      if (!check(p + i, qq[j])) {
        doit = false;
        break;
      }
    }
    if (doit) {
      if (q == qb) {
        if (n % 2 == 0 || qq[0] != n / 2)
          cnt += 2;
        else
          cnt++;
        continue;
      }
      qq[q] = p + i;
      ver[i] = 1;
      solve(q + 1);
      ver[i] = 0;
    }
  }
}

void ssolve() {
  for (int p = n / 2; p < n; p++) {
    qq[0] = p;
    solve(1);
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n;
  nn = n * n;
  qb = n - 1;
  if (n == 1)
    cout << 1;
  else {
    ssolve();
    cout << cnt;
  }
  return 0;
}