// BOJ 1016
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  vector<ll> sq;
  for (ll i = 1; i * i <= 1'000'001'000'000; i++)
    sq.push_back(i * i);

  ll mi, ma, c = 0;
  cin >> mi >> ma;
  for (auto i : sq) {
    if (ma < i)
      break;
    if (mi <= i)
      c++;
  }
  cout << c;

  return 0;
}
