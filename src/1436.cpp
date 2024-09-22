#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
char str[200];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt = 0;
  int num = 666;
  while (true) {
    sprintf(str, "%d", num);
    if (strstr(str, "666"))
      cnt++;
    if (cnt == n) {
      cout << num;
      return 0;
    }
    num++;
  }

  return 0;
}