#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  char y[101];
  char t[101];
  cin >> n >> y >> t;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (y[i] == t[i] && y[i] == 'C')
      c++;
  }
  cout << c;

  return 0;
}