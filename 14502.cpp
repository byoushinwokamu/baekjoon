#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int lab[64], llab[64];
int r, c, bd, sc; // row, column, border, virus count, space count
int safemax;
queue<int> q;
vector<int> v;

void copylab() {
  for (int i = 0; i < bd; i++)
    llab[i] = lab[i];
}

int bfs() { // returns safety area size
  int vvc = 0;
  copylab();
  for (auto i : v)
    q.push(i);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if (now % c > 0 && !llab[now - 1]) {
      llab[now - 1] = 2;
      q.push(now - 1);
      vvc++;
    }
    if (now % c < c - 1 && !llab[now + 1]) {
      llab[now + 1] = 2;
      q.push(now + 1);
      vvc++;
    }
    if (now >= c && !llab[now - c]) {
      llab[now - c] = 2;
      q.push(now - c);
      vvc++;
    }
    if (now < bd - c && !llab[now + c]) {
      llab[now + c] = 2;
      q.push(now + c);
      vvc++;
    }
  }
  return sc - vvc - 3;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> r >> c;
  bd = r * c;
  for (int i = 0; i < bd; i++) {
    cin >> lab[i];
    if (lab[i] == 0)
      sc++;
    else if (lab[i] == 2)
      v.push_back(i);
  }

  for (int i = 0; i < bd - 2; i++) {
    if (lab[i])
      continue;
    lab[i] = 1;
    for (int j = i + 1; j < bd - 1; j++) {
      if (lab[j])
        continue;
      lab[j] = 1;
      for (int k = j + 1; k < bd; k++) {
        if (lab[k])
          continue;
        lab[k] = 1;
        safemax = max(safemax, bfs());
        lab[k] = 0;
      }
      lab[j] = 0;
    }
    lab[i] = 0;
  }
  cout << safemax;

  return 0;
}