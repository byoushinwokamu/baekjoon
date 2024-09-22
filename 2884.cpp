#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int h, m;
  cin >> h >> m;
  if (m >= 45)
    m -= 45;
  else {
    m += 15;
    if (h == 0)
      h = 23;
    else
      h--;
  }
  cout << h << " " << m;
  return 0;
}