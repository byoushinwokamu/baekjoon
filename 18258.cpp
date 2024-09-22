#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  queue<int> q;
  char op[6];
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> op;
    switch (op[1]) {
    case 'u':
      cin >> x;
      q.push(x);
      break;
    case 'o':
      if (q.empty())
        cout << -1 << '\n';
      else {
        cout << q.front() << '\n';
        q.pop();
      }
      break;
    case 'i':
      cout << q.size() << '\n';
      break;
    case 'm':
      cout << (q.empty() ? 1 : 0) << '\n';
      break;
    case 'r':
      cout << (q.empty() ? -1 : q.front()) << '\n';
      break;
    case 'a':
      cout << (q.empty() ? -1 : q.back()) << '\n';
      break;
    }
  }
}