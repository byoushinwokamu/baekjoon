#include <cstring>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t, r;
  char str[21];
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    cin >> r >> str;
    for (int i = 0; i < strlen(str); i++)
      for (int j = 0; j < r; j++)
        cout << str[i];
    cout << "\n";
  }

  return 0;
}