// BOJ 1431
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
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end(), [](const string &a, const string &b)
       {
         if (a.length() != b.length()) return a.length() < b.length();
         int sa = 0, sb = 0;
         for (auto c : a)
           if (isdigit(c)) sa += c - '0';
         for (auto c : b)
           if (isdigit(c)) sb += c - '0';
         if (sa != sb) return sa < sb;
         for (int i = 0; i < a.length(); i++)
           if (a[i] != b[i]) return a[i] < b[i];
         return true;
       });

  for (auto s : v) cout << s << '\n';

  return 0;
}
