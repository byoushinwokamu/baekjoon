// BOJ 11000
#include <algorithm>
#include <iostream>
#include <queue>
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

typedef struct
{
  bool operator()(const pp &a, const pp &b) { return a.se > b.se; }
} comp;

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pp> lecture(n);
  for (int i = 0; i < n; i++) cin >> lecture[i];
  priority_queue<pp, vector<pp>, comp> room;
  sort(lecture.begin(), lecture.end(), [](const pp &a, const pp &b)
       { return a.fi != b.fi ? a.fi < b.fi : a.se < b.se; });

  int t = 0;
  for (int i = 0; i < n; i++)
  {
    if (!room.empty())
    {
      while (!room.empty() && room.top().se < lecture[i].fi)
      {
        room.pop();
      }
    }
    t = lecture[i].fi;
  }

  return 0;
}
