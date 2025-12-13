// BOJ 31880
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
  int n, m;
  cin >> n >> m;
  ll luck = 0;
  int i;
  while (n--) cin >> i, luck += i;
  while (m--) cin >> i, luck *= i ? i : 1;
  cout << luck;

  return 0;
}
