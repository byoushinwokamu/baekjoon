// BOJ 25595
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
  int n, a;
  cin >> n;
  vector<int> region;
  int shinei;
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
    {
      cin >> a;
      if (a == 1) region.push_back((r & 1) ^ (c & 1));
      else if (a == 2) shinei = ((r & 1) ^ (c & 1));
    }
  bool lena = true;
  for (auto i : region)
    if (i == shinei) lena = false;

  cout << (lena ? "Lena" : "Kiriya");

  return 0;
}
