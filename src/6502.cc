// BOJ 6502
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
  int r, w, l;
  cin >> r;
  for (int i = 1; r; i++)
  {
    cin >> w >> l;
    cout << "Pizza " << i;
    if (w * w + l * l <= 4 * r * r) cout << " fits on the table.\n";
    else cout << " does not fit on the table.\n";

    cin >> r;
  }

  return 0;
}
