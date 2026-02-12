// BOJ 7662
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
  bool operator()(const pp &a, const pp &b) { return a.fi < b.fi; }
} comp_maxheap;

typedef struct
{
  bool operator()(const pp &a, const pp &b) { return a.fi > b.fi; }
} comp_minheap;

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
  {
    int k, n;
    char c;
    cin >> k;
    priority_queue<pp, vector<pp>, comp_minheap> pqmin;
    priority_queue<pp, vector<pp>, comp_maxheap> pqmax; // fi: value, se: id
    vector<bool> ejected(k);
    for (int i = 0; i < k; i++)
    {
      cin >> c >> n;
      if (c == 'I') pqmin.push({n, i}), pqmax.push({n, i});
      else if (c == 'D')
      {
        while (!pqmin.empty() && ejected[pqmin.top().se]) pqmin.pop();
        while (!pqmax.empty() && ejected[pqmax.top().se]) pqmax.pop();
        if (!pqmin.empty())
        {
          if (n == -1)
          {
            ejected[pqmin.top().se] = true;
            pqmin.pop();
          }
          if (n == 1)
          {
            ejected[pqmax.top().se] = true;
            pqmax.pop();
          }
        }
      }
    }

    while (!pqmin.empty() && ejected[pqmin.top().se]) pqmin.pop();
    while (!pqmax.empty() && ejected[pqmax.top().se]) pqmax.pop();
    if (pqmin.empty()) cout << "EMPTY\n";
    else cout << pqmax.top().fi << ' ' << pqmin.top().fi << '\n';
  }

  return 0;
}
