// BOJ 8891
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  vector<int> tri(10001);
  vector<int> sam(10001);
  vector<int> sambef(10001);
  for (int i = 1; i <= 10000; i++)
    tri[i] = tri[i - 1] + i;
  int cur = 1;
  for (int i = 1; i <= 10000; i++)
  {
    if (tri[cur] < i) cur++;
    sam[i] = tri[cur], sambef[i] = tri[cur - 1];
  }

  while (t--)
  {
    int a, b;
    cin >> a >> b;
    int x, y;
    x = a - sambef[a] + b - sambef[b];
    y = sam[a] - a + 1 + sam[b] - b + 1;
    cout << tri[x + y - 1] - y + 1 << '\n';
  }

  return 0;
}
