// BOJ 1644
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> inp(4000001);
vector<int> prime;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  inp[1] = true;
  prime.push_back(0);
  for (int i = 2; i <= 4000001; i++)
  {
    if (inp[i]) continue;
    prime.push_back(i);
    for (int j = 2; i * j <= 4000001; j++)
      inp[i * j] = true;
  }
  int n;
  cin >> n;

  int acc = 0, cnt = 0;
  auto lft = prime.begin(), rht = prime.begin();
  while (lft != prime.end())
  {
    if (acc == n)
    {
      if (lft != prime.begin()) cnt++;
      acc -= *lft, lft++;
    }
    else if (acc < n)
    {
      if (rht == prime.end()) break;
      acc += *rht, rht++;
    }
    else if (acc > n)
    {
      acc -= *lft, lft++;
    }
  }

  cout << cnt;

  return 0;
}
