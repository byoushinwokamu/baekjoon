#include <cstring>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  char str[10];
  for (int i = 1; i < 1000000; i++) {
    sprintf(str, "%d", i);
    int s = i;
    int len = strlen(str);
    for (int j = 0; j < len; j++)
      s += static_cast<int>(str[j] - 48);
    if (s == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}