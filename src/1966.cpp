#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n, m, a;
    cin >> n >> m;
    queue<int> q;
    int p[10] = {
        0,
    };
    int maxp = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      q.push(a);
      p[a]++;
      maxp = maxp > a ? maxp : a;
    }
    int cnt = 0;
    while (true) {
      if (q.front() == maxp) {
        if (m == 0) {
          cout << ++cnt << '\n';
          break;
        }
        cnt++;
        if (--p[maxp] == 0)
          while (maxp > 0 && p[--maxp] == 0)
            ;
        q.pop();
        m = m > 0 ? m - 1 : n - cnt - 1;
      } else {
        q.push(q.front());
        q.pop();
        m = m > 0 ? m - 1 : n - cnt - 1;
      }
    }
  }

  return 0;
}