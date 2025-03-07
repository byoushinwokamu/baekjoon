// BOJ 14956
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

const pp POS[4] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};

pp operator+(const pp &a, const pp &b) { return {a.fi + b.fi, a.se + b.se}; }
pp operator*(const pp &a, const int &n) { return {a.fi * n, a.se * n}; }

int n, m;

void aruku(vector<vector<int>> &maze, pp st, int len, int k) {
  static int step = 0;
  static vector<int> v(15);
  if (len == 1) {
    if (++step == m) {
      cout << st.fi + 1 << ' ' << st.se + 1;
      exit(0);
    }
    return;
  }
  if ((k + v[k]++) % 2 == 0) {
    aruku(maze, st, len / 2, k + 1);
    aruku(maze, st + make_pair(0, len / 2), len / 2, k + 1);
    aruku(maze, st + make_pair(len / 2, len / 2), len / 2, k + 1);
    aruku(maze, st + make_pair(len / 2, 0), len / 2, k + 1);
  } else {
    aruku(maze, st, len / 2, k + 1);
    aruku(maze, st + make_pair(len / 2, 0), len / 2, k + 1);
    aruku(maze, st + make_pair(len / 2, len / 2), len / 2, k + 1);
    aruku(maze, st + make_pair(0, len / 2), len / 2, k + 1);
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  vector<vector<int>> maze(n, vector<int>(n));

  aruku(maze, {0, 0}, n, 0);

  return 0;
}
