// BOJ 1919
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  vector<int> a(26), b(26);
  string A, B;
  cin >> A >> B;
  for (auto c : A) a[c - 'a']++;
  for (auto c : B) b[c - 'a']++;
  int ans = 0;
  for (int i = 0; i < 26; i++)
    ans += abs(a[i] - b[i]);
  cout << ans;

  return 0;
}
