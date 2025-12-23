// BOJ 1009
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
  int t, a, b, r;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    r = 1;
    for (int i = 0; i < b; i++)
      r *= a, r %= 10;
    cout << (r ? r : 10) << '\n';
  }

  return 0;
}
