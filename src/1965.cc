// BOJ 1965
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
  int n, a;
  cin >> n;
  vector<int> lg(n);
  vector<int> sm;
  sm.reserve(n);

  cin >> a;
  lg[0] = 1;
  sm.push_back(a);

  for (int i = 1; i < n; i++)
  {
    cin >> a;
    lg[i] = lower_bound(sm.begin(), sm.end(), a) - sm.begin();
    if (lg[i] == sm.size()) sm.push_back(a);
    else sm[lg[i]] = min(sm[lg[i]], a);
  }
  cout << sm.size();

  return 0;
}
