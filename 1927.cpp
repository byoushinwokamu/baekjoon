#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > 0)
      pq.push(x);
    else {
      cout << (pq.empty() ? 0 : pq.top()) << '\n';
      if (!pq.empty())
        pq.pop();
    }
  }
  return 0;
}