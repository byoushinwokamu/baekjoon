// BOJ 30648
#include <algorithm>
#include <iostream>
#include <queue>
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
  int a, b, r;
  cin >> a >> b >> r;
  vector<vector<int>> garden(r, vector<int>(r));
  pp trick = {a, b};

  queue<pair<pp, int>> bloom;
  bloom.push({trick, 0});
  while (!bloom.empty())
  {
    a = bloom.front().fi.fi;
    b = bloom.front().fi.se;
    int t = bloom.front().se;
    bloom.pop();
    if (++garden[a][b] == 2)
    {
      cout << t;
      return 0;
    }

    if (a + b + 2 < r)
      bloom.push({{a + 1, b + 1}, t + 1});
    else
      bloom.push({{a / 2, b / 2}, t + 1});
  }

  return 0;
}
