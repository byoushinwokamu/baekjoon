// BOJ 30468
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
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  a += b + c + d;
  n *= 4;
  cout << (n > a ? n - a : 0);

  return 0;
}
