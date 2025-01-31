// BOJ 1755
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

const char dic[] = {'z', 'o', 'u', 't', 'g', 'f', 's', 'r', 'e', 'n'};
bool cmpchar(const int &a, const int &b) { return dic[a] < dic[b]; }
bool cmpint(const int &a, const int &b) {
  int af = a / 10, ar = a % 10, bf = b / 10, br = b % 10;
  if (af && bf) {
    if (af != bf)
      return cmpchar(af, bf);
    else
      return cmpchar(ar, br);
  } else if (af) {
    if (af != br)
      return cmpchar(af, br);
    else
      return false;
  } else if (bf) {
    if (ar != bf)
      return cmpchar(ar, bf);
    else
      return true;
  } else {
    return cmpchar(ar, br);
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int m, n;
  cin >> m >> n;
  vector<int> v;
  for (int i = m; i <= n; i++)
    v.push_back(i);
  sort(v.begin(), v.end(), cmpint);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << (i % 10 == 9 ? '\n' : ' ');
  }

  return 0;
}
