#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<int> sq(1);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int m, n, minn = 10001, summ = 0;
  for (int i = 1; i <= 100; i++)
    sq.push_back(i * i);
  cin >> m >> n;
  for (int i : sq) {
    if (m <= i && i <= n) {
      if (minn == 10001)
        minn = i;
      summ += i;
    }
  }
  if (summ)
    cout << summ << '\n' << minn;
  else
    cout << -1;

  return 0;
}
