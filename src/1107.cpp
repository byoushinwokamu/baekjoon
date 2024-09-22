#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m; // n = destination, m = num of broken buttons
  char broken[10];
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> broken[i];
  int best = abs(n - 100);
  char str[7];

  for (int i = 0; i <= 1111111; i++) {
    sprintf(str, "%d", i);
    for (int j = 0; j <= m; j++) {
      if (j == m)
        best = min((int)best, (int)(strlen(str) + abs(n - i)));
      if (strchr(str, broken[j]))
        break;
    }
  }

  cout << best;

  return 0;
}