// BOJ 13913
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

  int n, k;
  cin >> n >> k;
  vector<bool> vis(100001);
  vector<int> from(100001);

  queue<int> q;
  q.push(n);
  while (!q.empty())
  {
    int now = q.front();
    q.pop();

    if (now == k)
    {
      stack<int> st;
      while (now != n)
        st.push(now), now = from[now];
      cout << st.size() << '\n';
      cout << now << ' ';
      while (!st.empty())
      {
        cout << st.top() << " ";
        st.pop();
      }
      return 0;
    }

    if (now > 0 && !vis[now - 1])
    {
      vis[now - 1] = true;
      from[now - 1] = now;
      q.push(now - 1);
    }
    if (now < 100000 && !vis[now + 1])
    {
      vis[now + 1] = true;
      from[now + 1] = now;
      q.push(now + 1);
    }
    if (now <= 50000 && !vis[now << 1])
    {
      vis[now << 1] = true;
      from[now << 1] = now;
      q.push(now << 1);
    }
  }

  return 0;
}
