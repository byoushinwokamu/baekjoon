// BOJ 2467
#include <algorithm>
#include <cmath>
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
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int san = 0, yom = n - 1;
  int lft, rht, mid;
  while (true)
  {
    if (v[san] + v[yom] < 0)
    {
      // cout << "S" << endl;
      // move san
      int sannew = lower_bound(v.begin() + san, v.begin() + yom, -v[yom]) - v.begin();
      if (sannew + 1 < yom && abs(v[sannew] + v[yom]) > abs(v[sannew + 1] + v[yom]))
      {
        sannew++;
      }
      if (abs(v[sannew] + v[yom]) > abs(v[san] + v[yom])) sannew = san;
      if (sannew == san)
      {
        cout << v[san] << ' ' << v[yom];
        break;
      }
      san = sannew;
    }
    else if (v[san] + v[yom] > 0)
    {
      // cout << "Y" << endl;
      // move yom
      int yomnew = lower_bound(v.begin() + san + 1, v.begin() + yom + 1, -v[san]) - v.begin();
      if (san < yomnew + 1 && yomnew + 1 != n && abs(v[san] + v[yomnew]) > abs(v[san] + v[yomnew + 1]))
      {
        yomnew++;
      }
      if (abs(v[san] + v[yomnew]) > abs(v[san] + v[yom])) yomnew = yom;
      if (yomnew == yom)
      {
        cout << v[san] << ' ' << v[yom];
        break;
      }
      yom = yomnew;
    }
    else
    {
      cout << v[san] << ' ' << v[yom];
      break;
    }
  }

  return 0;
}
