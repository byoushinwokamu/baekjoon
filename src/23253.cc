// BOJ 23253
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
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> v(m);
  for (int i = 0; i < m; i++)
  {
    cin >> a;
    for (int j = 0; j < a; j++)
      cin >> b, v[i].push_back(b);

    bool des = true;
    for (int j = 1; j < a; j++)
      if (v[i][j - 1] < v[i][j])
        des = false;
    if (!des)
    {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";

  return 0;
}
