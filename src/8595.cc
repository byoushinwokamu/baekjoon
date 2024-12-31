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
  string s;
  int n;
  cin >> n >> s;
  ll h = 0, hs = 0;
  for (auto c : s) {
    if (c >= '0' && c <= '9')
      h *= 10, h += c - '0';
    else
      hs += h, h = 0;
  }
  cout << hs + h;

  return 0;
}
