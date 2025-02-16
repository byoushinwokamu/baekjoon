// BOJ 1283
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> key(26 + 'A');

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  cin.ignore();
  vector<string> op(n); // option
  vector<int> sc(n);    // shortcut
  for (int i = 0; i < n; i++) {
    bool found = false;
    getline(cin, op[i]);
    sc[i] = -1;

    if (!key[toupper(op[i][0])]) {
      key[toupper(op[i][0])] = true;
      sc[i] = 0;
      found = true;

    } else {
      for (int j = 2; j < op[i].length() - 1; j++) {
        if (op[i][j] == ' ' && !key[toupper(op[i][j + 1])]) {
          key[toupper(op[i][j + 1])] = true;
          sc[i] = j + 1;
          break;
        }
      }
    }

    if (sc[i] == -1) {
      for (int j = 1; j < op[i].length(); j++) {
        if (op[i][j] == ' ')
          continue;
        if (!key[toupper(op[i][j])]) {
          key[toupper(op[i][j])] = true;
          sc[i] = j;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (sc[i] == -1) {
      cout << op[i] << '\n';
      continue;
    }
    int j;
    for (j = 0; j < sc[i]; j++)
      cout << op[i][j];
    cout << '[' << op[i][sc[i]] << ']';
    for (j++; j < op[i].length(); j++)
      cout << op[i][j];
    cout << '\n';
  }

  return 0;
}
