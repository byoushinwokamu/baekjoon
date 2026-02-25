// BOJ 2096
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

vector<int> bp(3);
vector<int> wp(3);
vector<int> bn(3);
vector<int> wn(3);
vector<int> sc(3);

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> sc[0] >> sc[1] >> sc[2];
    bn[0] = max(bp[0], bp[1]) + sc[0];
    bn[1] = max({bp[0], bp[1], bp[2]}) + sc[1];
    bn[2] = max(bp[1], bp[2]) + sc[2];
    wn[0] = min(wp[0], wp[1]) + sc[0];
    wn[1] = min({wp[0], wp[1], wp[2]}) + sc[1];
    wn[2] = min(wp[1], wp[2]) + sc[2];
    bp = bn, wp = wn;
  }
  cout << max({bp[0], bp[1], bp[2]});
  cout << ' ';
  cout << min({wp[0], wp[1], wp[2]});

  return 0;
}
