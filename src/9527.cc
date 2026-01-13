// BOJ 9527
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
  ll a, b;
  cin >> a >> b;
  ll cnt = 0;
  for (a; a <= b; a++)
  {
    if (a & 1) cnt++;
    a >>= 1;
  }
  cout << cnt;

  return 0;
}
