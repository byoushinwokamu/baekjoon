#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  stack<int> st;
  char op[6];
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> op;
    switch (op[0]) {
    case 'p':
      if (op[1] == 'u') {
        cin >> x;
        st.push(x);
      } else {
        if (st.empty())
          cout << -1 << '\n';
        else {
          cout << st.top() << '\n';
          st.pop();
        }
      }
      break;
    case 's':
      cout << st.size() << '\n';
      break;
    case 'e':
      cout << (st.empty() ? 1 : 0) << '\n';
      break;
    case 't':
      cout << (st.empty() ? -1 : st.top()) << '\n';
      break;
    }
  }
}