#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> q;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    q.push(-a);
  }
  for (int i = 0; i < n; i++) {
    cout << -q.top() << '\n';
    q.pop();
  }

  return 0;
}