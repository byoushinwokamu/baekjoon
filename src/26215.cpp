#include <iostream>

using namespace std;
int n, t, tot, time, maxx;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    maxx = maxx > t ? maxx : t;
    tot += t;
  }
  time = tot / 2 + (tot - 2 * maxx) % 2;
  if (tot < 2 * maxx)
    time = maxx;

  cout << (time > 1440 ? -1 : time);

  return 0;
}