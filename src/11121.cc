// BOJ 11121
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
  int t;
  string a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << (a == b ? "OK\n" : "ERROR\n");
  }

  return 0;
}
