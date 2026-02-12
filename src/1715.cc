// BOJ 1715
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

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, a;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) cin >> a, pq.push(a);

  int deck;
  ll comp = 0;
  while (pq.size() > 1)
  {
    deck = pq.top(), pq.pop();
    deck += pq.top(), pq.pop();
    pq.push(deck);
    comp += deck;
  }
  cout << comp;

  return 0;
}
