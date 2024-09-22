#include <deque>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  deque<int> d;

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    d.push_back(i + 1);

  int pos, cnt;
  int op = 0;
  for (int i = 0; i < m; i++) {
    cin >> pos;
    cnt = 0;
    while (d.front() != pos) {
      d.push_back(d.front());
      d.pop_front();
      cnt++;
    }
    d.pop_front();
    op += (cnt * 2 > n ? n - cnt : cnt);
    n--;
  }
  cout << op;

  return 0;
}