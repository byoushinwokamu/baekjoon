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
  int k;
  cin >> k;

  int i, j;
  for (int i = 0; i < k; i++) {
    for (j = 0; j < k; j++)
      cout << 'G';
    for (j; j < 4 * k; j++)
      cout << '.';
    cout << '\n';
  }

  for (int i = 0; i < k; i++) {
    for (j = 0; j < k; j++)
      cout << '.';
    for (j; j < 2 * k; j++)
      cout << 'I';
    for (j; j < 3 * k; j++)
      cout << '.';
    for (j; j < 4 * k; j++)
      cout << 'T';
    cout << '\n';
  }

  for (int i = 0; i < k; i++) {
    for (j = 0; j < 2 * k; j++)
      cout << '.';
    for (j; j < 3 * k; j++)
      cout << 'S';
    for (j; j < 4 * k; j++)
      cout << '.';
    cout << '\n';
  }

  return 0;
}
