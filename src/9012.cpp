#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  char str[51];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    stack<char> st;
    for (char c : str) {
      if (c == '\0')
        break;
      st.push(c);
    }

    int now = 0;
    bool cant = false;
    while (!st.empty()) {
      switch (st.top()) {
      case ')':
        now++;
        break;
      case '(':
        if (now)
          now--;
        else
          cant = true;
        break;
      }
      st.pop();
    }
    if (!cant && now == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}