// BOJ 5648
#include <algorithm>
#include <cstring>
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
  int n;
  cin >> n;
  char str[14];
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = strlen(str) - 1; j >= 0; j--)
      v[i] *= 10, v[i] += str[j] - '0';
  }
  sort(v.begin(), v.end());
  for (auto ln : v)
    cout << ln << '\n';

  return 0;
}
