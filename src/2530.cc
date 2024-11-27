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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  c += d;
  b += c / 60, c %= 60;
  a += b / 60, b %= 60;
  a %= 24;
  cout << a << ' ' << b << ' ' << c;

  return 0;
}
