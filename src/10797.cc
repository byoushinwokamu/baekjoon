// BOJ 10797
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
  int d, c = 0, n;
  cin >> d;
  for (int i = 0; i < 5; i++) {
    cin >> n;
    if (d == n)
      c++;
  }
  cout << c;

  return 0;
}
