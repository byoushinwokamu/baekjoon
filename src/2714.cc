// BOJ 2714
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int r, c, dir = 1;
string s;
int gopos(int pos)
{
  int rr = pos / c, cc = pos % c;
  if (dir == 1)
    if (cc + 1 < c && s[rr * c + cc + 1]) dir;
    else dir = c;
  else if (dir == c)
    if (rr + 1 < r && s[(rr + 1) * c + cc]) dir;
    else dir = -1;
  else if (dir == -1)
    if (cc - 1 >= 0 && s[rr * c + cc - 1]) dir;
    else dir = -c;
  else if (dir == -c)
    if (rr - 1 >= 0 && s[(rr - 1) * c + cc]) dir;
    else dir = 1;
  return s[pos + dir] ? pos + dir : -1;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> r >> c >> s;
    int pos = 0;
    int buf = 0, cnt = 0, slen = -1;
    dir = 1;
    string ans;
    while (pos != -1)
    {
      // cout << "pos " << pos << '\n';
      buf <<= 1, buf += s[pos] - '0';
      if (++cnt == 5)
      {
        cnt = 0;
        ans.push_back(buf ? buf + 'A' - 1 : ' ');
        if (buf) slen = ans.length();
        // cout << "buf " << buf << '\n';
        buf = 0;
      }

      s[pos] = 0;
      pos = gopos(pos);
    }
    for (int i = 0; i < slen; i++) cout << ans[i];
    cout << '\n';
  }

  return 0;
}
