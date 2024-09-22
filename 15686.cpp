#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> hom;
vector<int> chi;
int len[100][13];
int n, m, hh, cc, city; // max n=50, m=13, hh=2n(100), cc=13
bool vis[13];
int dis, dissum, dismin = 1e9;

int cdis(int a, int b) { return abs(a / 50 - b / 50) + abs(a % 50 - b % 50); }

void dfs(int level, int st) {
  if (level == m) {
    dissum = 0;
    for (int i = 0; i < hh; i++) {
      dis = 1e9;
      for (int j = 0; j < cc; j++) {
        if (!vis[j])
          continue;
        dis = min(dis, len[i][j]);
      }
      dissum += dis;
    }
    dismin = min(dismin, dissum);
    return;
  }
  for (int i = st; i < cc; i++) {
    if (vis[i])
      continue;
    vis[i] = true;
    dfs(level + 1, i + 1);
    vis[i] = false;
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  // input
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> city;
      if (city == 1)
        hom.push_back(i * 50 + j);
      else if (city == 2)
        chi.push_back(i * 50 + j);
    }
  }
  hh = hom.size();
  cc = chi.size();
  for (int i = 0; i < hh; i++)
    for (int j = 0; j < cc; j++)
      len[i][j] = cdis(hom[i], chi[j]);
  dfs(0, 0);
  cout << dismin;

  return 0;
}