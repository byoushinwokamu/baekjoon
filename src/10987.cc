// BOJ 10987
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
  string s;
  cin >> s;
  int m = 0;
  for (auto c : s) {
    if (strchr("aeiou", c))
      m++;
  }
  cout << m;

  return 0;
}
