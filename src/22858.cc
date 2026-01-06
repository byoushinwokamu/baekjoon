// BOJ 22858
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
  int n, k;
  cin >> n >> k;
  vector<int> c1(n);
  vector<int> c2(n);
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> c1[i];
  for (int i = 0; i < n; i++) cin >> d[i];

  auto *src = &c1;
  auto *dest = &c2;
  auto *temp = &c2;
  while (k--)
  {
    for (int i = 0; i < n; i++)
      (*dest)[d[i] - 1] = (*src)[i];
    temp = src;
    src = dest;
    dest = temp;
  }
  for (int i = 0; i < n; i++)
    cout << (*src)[i] << ' ';
  return 0;
}
