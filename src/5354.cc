// BOJ 5354
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
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    if (n == 1)
    {
      cout << "#\n\n";
      continue;
    }
    for (int i = 0; i < n; i++) cout << '#';
    cout << endl;
    for (int i = 1; i < n - 1; i++)
    {
      cout << '#';
      for (int i = 1; i < n - 1; i++) cout << 'J';
      cout << '#';
      cout << endl;
    }
    for (int i = 0; i < n; i++) cout << '#';
    cout << endl
         << endl;
  }

  return 0;
}
