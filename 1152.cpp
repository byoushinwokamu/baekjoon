#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  string str;
  getline(cin, str);
  int i = 0;
  int len = str.length();
  while (str[i] == 32)
    i++;
  int cnt = 0;
  while (i < len && str[i] != 0) {
    cnt++;
    while (str[i] != 32) {
      i++;
      if (i >= len)
        break;
    }
    i++;
  }
  cout << cnt;
  return 0;
}