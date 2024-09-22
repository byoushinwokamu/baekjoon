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

  cin >> str;
  stack<char> st;
  for (char c : str) {
    if (c == '\0')
      break;
    st.push(c);
  }

  int now = 0;
  int piece = 0;
  char former = 0;
  while (!st.empty()) {
    switch (st.top()) {
    case ')':
      now++;
      piece++;
      former = ')';
      break;
    case '(':
      if (former == ')') {
        piece--;
        piece += --now;
      } else
        now--;
      former = '(';
      break;
    }
    st.pop();
  }
  cout << piece;

  return 0;
}