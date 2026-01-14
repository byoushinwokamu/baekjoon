// BOJ 12015
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int a;
vector<int> sm; // lg값의 최소 등장 a

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  sm.reserve(n);
  int lgg = 1;
  cin >> a;
  sm.push_back(a);
  for (int i = 1; i < n; i++)
  {
    cin >> a;
    if (sm.back() < a) sm.push_back(a);
    else *lower_bound(sm.begin(), sm.end(), a) = a;
  }
  cout << sm.size();

  return 0;
}
