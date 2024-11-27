#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<string> gz;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  int a, b, c, ten = 0;
  bool cor;
  cin >> n >> m;
  gz.resize(3 * n);
  for (int i = 0; i < 3 * n; i++)
    cin >> gz[i];

  for (int i = 1; i < 3 * n; i += 3) {
    for (int j = 1; j < 8 * m; j += 8) {
      a = gz[i][j] - '0';
      b = gz[i][j + 2] - '0';
      c = gz[i][j + 4] - '0';
      if (gz[i][j + 5] != '.')
        ten = 1, c *= 10, c += gz[i][j + 5] - '0';
      else
        ten = 0;

      switch (gz[i][j + 1]) {
      case '+':
        cor = (a + b == c);
        break;
      case '-':
        cor = (a - b == c);
        break;
      case '/':
        cor = (b == 0 ? false : (b * c == a));
        break;
      case '*':
        cor = (a * b == c);
        break;
      }
      if (cor) {
        for (int k = 0; k < (ten ? 6 : 5); k++)
          gz[i - 1][j + k] = '*', gz[i + 1][j + k] = '*';
        gz[i][j - 1] = '*', gz[i][j + (ten ? 6 : 5)] = '*';
      } else {
        gz[i - 1][j + 2] = '/', gz[i][j + 1] = '/', gz[i + 1][j] = '/';
      }
    }
  }
  for (auto s : gz) {
    cout << s << '\n';
  }

  return 0;
}
