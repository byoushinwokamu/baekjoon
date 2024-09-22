#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, maxdis_global = INT32_MAX;
vector<pair<int, int>> house;
vector<int> dps; // daepiso index

int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int depth, int tail) {
  if (depth == k) {
    int maxdis = 0;
    for (auto h : house) {
      int mindis_local = INT32_MAX;
      for (auto i : dps) {
        mindis_local =
            min(mindis_local, dist(h, house[i])); // find nearest dps at house h
      }
      maxdis = max(maxdis, mindis_local); // set max distance at the dps setting
    }
    maxdis_global =
        min(maxdis_global, maxdis); // update m_g if the setting is optimized

  } else {
    for (int i = tail + 1; i < n; i++) {
      dps.push_back(i);
      dfs(depth + 1, i);
      dps.pop_back();
    }
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    house.push_back({x, y});
  }
  dfs(0, -1);
  cout << maxdis_global;

  return 0;
}