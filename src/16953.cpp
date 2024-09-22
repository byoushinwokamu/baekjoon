#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  long long a, b;
  cin >> a >> b;
  queue<pair<long long, long long>> q;
  q.push(make_pair(a, 1));
  while (!q.empty()) {
    long long n = q.front().first, m = q.front().second;
    q.pop();
    if (n == b) {
      cout << m;
      return 0;
    }
    if (n <= 1000000000 && n < b) {
      q.push(make_pair(n * 10 + 1, m + 1));
      q.push(make_pair(n * 2, m + 1));
    }
  }
  cout << -1;

  return 0;
}