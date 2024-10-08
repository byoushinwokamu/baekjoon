#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  priority_queue<int> pq;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0) {
      if (pq.empty())
        cout << 0 << '\n';
      else
        cout << pq.top() << '\n', pq.pop();
    } else
      pq.push(x);
  }

  return 0;
}