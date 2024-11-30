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

vector<string> room(5);
vector<pp> princess(7);
int cnt;
int s, y;
pp dps[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}

bool validpos(const pp &p) {
  return (p.fi >= 0) && (p.fi < 5) && (p.se >= 0) && (p.se < 5);
}

int dist(const pp &p1, const pp &p2) {
  return abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
}

bool connected() {
  queue<int> q;
  q.push(0);
  vector<bool> con(7);
  con[0] = true;

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < 7; i++) {
      if (i == now)
        continue;
      if (!con[i] && dist(princess[i], princess[now]) == 1) {
        q.push(i);
        con[i] = true;
      }
    }
  }

  bool allcon = true;
  for (auto b : con)
    allcon = allcon && b;
  return allcon;
}

void dfs(int depth, int last) {
  if (depth == 7) {
    if (connected()) {
      int s = 0;
      for (auto p : princess) {
        if (room[p.fi][p.se] == 'S')
          s++;
      }
      if (s >= 4)
        cnt++;
    }
    return;
  }
  for (int a = last + 1; a < 19 + depth; a++) {
    princess[depth] = {a / 5, a % 5};
    dfs(depth + 1, a);
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  for (int i = 0; i < 5; i++)
    cin >> room[i];

  dfs(0, -1);
  cout << cnt;

  return 0;
}
