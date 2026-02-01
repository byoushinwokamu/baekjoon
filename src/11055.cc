// BOJ 11055
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
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> bg(n);
  int bgg = 0;

  cin >> a[0];
  bg[0] = a[0];
  bgg = bg[0];

  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    bg[i] = a[i];
    for (int j = i - 1; j >= 0; j--)
    {
      if (a[j] < a[i])
      {
        bg[i] = max(bg[i], bg[j] + a[i]);
      }
    }
    bgg = max(bgg, bg[i]);
  }
  cout << bgg;

  return 0;
}
