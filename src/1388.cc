#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<string> fl(50);
vector<vector<bool>> vis(50, vector<bool>(50));

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> fl[i];

  int pj = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j])
        continue;
      pj++;
      vis[i][j] = true;
      if (fl[i][j] == '|')
        for (int di = i + 1; di < n && fl[di][j] == '|'; di++)
          vis[di][j] = true;
      if (fl[i][j] == '-')
        for (int dj = j + 1; dj < m && fl[i][dj] == '-'; dj++)
          vis[i][dj] = true;
    }
  }
  cout << pj;

  return 0;
}
