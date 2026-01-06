// BOJ 4097
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
  int n;
  cin >> n;
  while (n)
  {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int nowgain = 0, bestgain = 0, minminus = 0;
    for (int i = 0; i < n; i++)
    {
      nowgain += v[i];
      bestgain = max(bestgain, nowgain);
      if (nowgain < 0) nowgain = 0;
      if (v[i] < 0)
      {
        if (minminus == 0) minminus = v[i];
        else minminus = max(minminus, v[i]);
      }
    }
    cout << (bestgain > 0 ? bestgain : minminus) << '\n';

    cin >> n;
  }

  return 0;
}
