// BOJ 2342
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

unsigned int e[100001][5][5];

constexpr unsigned int novis = __UINT32_MAX__;

int getpower(const pp &fr, const pp &to)
{
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, i;
  memset(e, 0xffffffff, 100001 * 5 * 5 * sizeof(unsigned int));
  e[0][0][0] = 0;

  cin >> n;
  for (i = 1; n; i++)
  {
    int lft, rht;

    rht = n;
    for (lft = 0; lft < 5; lft++)
    {
      if (lft == n) continue;
    }

    cin >> n;
  }
  unsigned int mine = __UINT32_MAX__;
  for (int k = 0; k < 20; k++)
    cout << e[i - 1][k] << ' ', mine = min(mine, e[i - 1][k]);
  // mine = min(mine, e[i - 1][k]);
  cout << mine;

  return 0;
}
