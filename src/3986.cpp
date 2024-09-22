#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  char str[100001];

  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    stack<char> st;
    for (char c : str) {
      if (c == '\0')
        break;
      st.push(c);
    }

    stack<char> now;
    while (!st.empty()) {
      switch (st.top()) {
      case 'A':
        if (now.empty() || now.top() == 'B')
          now.push('A');
        else
          now.pop();
        break;
      case 'B':
        if (now.empty() || now.top() == 'A')
          now.push('B');
        else
          now.pop();
        break;
      }
      st.pop();
    }
    if (now.empty())
      count++;
  }
  cout << count;

  return 0;
}