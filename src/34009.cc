// BOJ 34009
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
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<ll>());
  ll a = 0, b = 0;
  for (int i = 0; i < n; i++)
  {
    if ((n - i) % 2 == 0) a += v[i];
    else b += v[i];
    if (a <= b)
    {
      cout << "Bob";
      return 0;
    }
  }
  cout << "Alice";

  return 0;
}
