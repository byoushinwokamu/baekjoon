#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int minbag = 2000;
  for (int i = 0; i < 1700; i++) {
    for (int j = 0; j < 1100; j++) {
      if (n == 3 * i + 5 * j)
        minbag = minbag < i + j ? minbag : i + j;
    }
  }
  cout << (minbag == 2000 ? -1 : minbag);

  return 0;
}