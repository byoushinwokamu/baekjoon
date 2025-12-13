// BOJ 17123
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
  while (t--)
  {
    int n, m, a;
    int r1, r2, c1, c2, v;
    cin >> n >> m;
    vector<int> row(n), col(n);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> a, row[i] += a, col[j] += a;

    for (int k = 0; k < m; k++)
    {
      cin >> r1 >> c1 >> r2 >> c2 >> v;
      for (int i = r1 - 1; i < r2; i++)
        row[i] += v * (c2 - c1 + 1);
      for (int j = c1 - 1; j < c2; j++)
        col[j] += v * (r2 - r1 + 1);
    }

    for (auto n : row) cout << n << ' ';
    cout << '\n';
    for (auto n : col) cout << n << ' ';
    cout << '\n';
  }

  return 0;
}
