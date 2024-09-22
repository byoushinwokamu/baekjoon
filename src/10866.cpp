#include <deque>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  deque<int> q;
  char op[11];
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> op;
    switch (op[1]) {
    case 'u':
      cin >> x;
      if (op[5] == 'f')
        q.push_front(x);
      else
        q.push_back(x);
      break;
    case 'o':
      if (q.empty())
        cout << -1 << '\n';
      else if (op[4] == 'f') {
        cout << q.front() << '\n';
        q.pop_front();
      } else {
        cout << q.back() << '\n';
        q.pop_back();
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