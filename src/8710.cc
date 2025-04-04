// BOJ 8710
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
  int k, w, m;
  cin >> k >> w >> m;

  int c = 0;
  while (k < w) {
    k += m;
    c++;
  }
  cout << c;

  return 0;
}
