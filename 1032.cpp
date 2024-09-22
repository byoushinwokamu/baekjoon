#include <cstring>
#include <iostream>

using namespace std;

int n;
char f[50][51];
char res[51];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> f[i];

  int len = strlen(f[0]);

  int in = 0;
  for (int i = 0; i < len; i++) {
    res[i] = f[0][i];
    if (res[i] == 0)
      break;
    for (int j = 1; j < n; j++) {
      if (res[i] != f[j][i]) {
        res[i] = '?';
        break;
      }
    }
  }
  cout << res;

  return 0;
}