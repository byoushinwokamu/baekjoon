// BOJ 14614
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
  int a, b;
  string c;
  cin >> a >> b >> c;
  int cc = *(c.end() - 1) - 48;
  if (cc % 2)
    a ^= b;
  cout << a;

  return 0;
}
