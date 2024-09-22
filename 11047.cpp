#include <iostream>

using namespace std;

int n, k;
int coin[10];

int f(int now, int cnt, int nokori) {
  if (now == 0)
    return cnt + nokori;
  if (coin[now] > nokori)
    return f(now - 1, cnt, nokori);
  return f(now - 1, cnt + (nokori / coin[now]), (nokori % coin[now]));
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> coin[i];

  cout << f(n - 1, 0, k);
  return 0;
}