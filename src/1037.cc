#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int y;
  cin >> y;
  vector<int> yak(y);
  for (int i = 0; i < y; i++)
    cin >> yak[i];
  sort(yak.begin(), yak.end());
  cout << yak[0] * yak[y - 1];

  return 0;
}
