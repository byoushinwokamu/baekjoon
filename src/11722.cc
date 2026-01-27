// BOJ 11722
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
  vector<int> lg(n, 1001);
  int lgg = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    for (int j = lgg; j >= 0; j--)
    {
      if (lg[j] < a)
      {
        lg[j + 1] = a, lgg = max(lgg, j + 1);
        break;
      }
    }
  }

  cout << lgg;

  return 0;
}
