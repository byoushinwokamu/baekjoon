// BOJ 11656
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
  string s;
  cin >> s;
  vector<string> v;
  for (int i = s.length(); i > 0; i--)
    v.push_back(s.substr(i - 1));
  sort(v.begin(), v.end());
  for (auto str : v) cout << str << '\n';

  return 0;
}
