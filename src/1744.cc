// BOJ 1744
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
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<int>());

  int s = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1) s += v[i];
    else
    {
      if (v[i] * v[i + 1] > v[i] + v[i + 1]) s += v[i] * v[i + 1], i++;
      else s += v[i];
    }
  }
  cout << s;

  return 0;
}
