// BOJ 15701
#include <algorithm>
#include <cmath>
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
  int n, c = 0;
  cin >> n;
  int sq = round(pow(n, 0.5));
  int i;
  for (i = 1; i <= sq; i++)
  {
    if (n % i == 0) c += (n / i == i ? 1 : 2);
  }
  cout << c;

  return 0;
}
