#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

typedef vector<deque<int>> vv;

int n, t;
vv a, b;
int gs[11] = {0, 1, 3, 6, 10, 15, 21, 28, 35, 45, 55};
int md = 60;

void rotate() {
  for (auto v : a)
    for (int i = 0; i < v.size() / 3; i++)
      v.push_back(v.front()), v.pop_front();
}

void mirror() {
  for (auto v : a)
    for (int i = 0; i < v.size() / 2; i++)
      t = v[i], v[i] = v[v.size() - i - 1], v[v.size() - i - 1] = t;
}

void diff() {
  int dd = 0;
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[i].size(); j++)
      (a[i][j] != b[i][j]) ? dd++ : dd;
  md = min(md, dd);
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  int t, i, l;
  int level = (n + 2) / 3 - 1;
  a.resize(level);
  b.resize(level);

  for (i = 0; i < n - level; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> t;
      if (j <= i / 2)
        a[j].push_front(t);
      else
        a[i - j].push_back(t);
    }
  }
  for (i; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j < n - i - 2) {
        cin >> t;
        a[j].push_front(t);
      } else if (i - j <= j) {
        cin >> t;
        a[j].push_front(t);
      } else {
        cin >> t;
        a[j].push_front(t);
      }
    }
  }

  for (i = 0; i < n - level; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> t;
      if (j <= i / 2)
        b[j].push_front(t);
      else
        b[i - j].push_back(t);
    }
  }
  for (i; i < n; i++) {
    l = 0;
    for (int j = 0; j <= i; j++) {
      if (l < n - i - 1) {
        cin >> t;
        b[l].push_front(t);
        l++;
      } else if (i - j <= l) {
        l--;
        cin >> t;
        b[l].push_front(t);
      } else {
        cin >> t;
        b[l].push_front(t);
      }
    }
  }

  cout << "A\n";
  for (auto v : a) {
    for (auto d : v)
      cout << d << ' ';
    cout << '\n';
  }
  diff();

  rotate();
  diff();

  rotate();
  diff();

  mirror();
  diff();

  rotate();
  diff();

  rotate();
  diff();

  cout << md;

  return 0;
}
