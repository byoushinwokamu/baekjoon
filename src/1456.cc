// BOJ 1456
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<ll> prime;
vector<bool> inp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll a, b, c = 0;
  cin >> a >> b;

  for (ll i = 1; i * i <= b; i++) {
    if (i * i < a)
      continue;
    c++;
  }

  cout << c;

  return 0;
}
