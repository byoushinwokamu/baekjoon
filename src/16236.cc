#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, a;
vector<vector<int>> space(20, vector<int>(20, -1));
vector<int> fishn(7);
vector<vector<vector<bool>>> visit(7);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  queue<pair<pp, pp>> q; // xpos, ypos, size, time
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> space[i][j];
      if (space[i][j] == 9)
        q.push({{i, j}, {2, 1}});
    }
  }

  return 0;
}
