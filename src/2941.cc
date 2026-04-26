// BOJ 2941
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
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (i < s.size() - 1)
    {
      if (s[i] == 'c' && s[i + 1] == '=')
        i++;
      else if (s[i] == 'c' && s[i + 1] == '-')
        i++;
      else if (s[i] == 'd' && s[i + 1] == '-')
        i++;
      else if (s[i] == 'l' && s[i + 1] == 'j')
        i++;
      else if (s[i] == 'n' && s[i + 1] == 'j')
        i++;
      else if (s[i] == 's' && s[i + 1] == '=')
        i++;
      else if (s[i] == 'z' && s[i + 1] == '=')
        i++;
    }
    if (i < s.size() - 2)
    {
      if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')
        i += 2;
    }
    cnt++;
  }
  cout << cnt;

  return 0;
}
