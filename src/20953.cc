// BOJ 20953
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
  int t, a, b;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    cout << ((a + b - 1) * (a + b) / 2 * (a + b)) << '\n';
  }

  return 0;
}
