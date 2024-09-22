#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  char s[150];
  cin >> s;
  stack<char> st;
  char res[150];
  int cur = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    char c = s[i];
    switch (c) {
    case '*':
    case '/':
      while (!st.empty() && (st.top() == '*' || st.top() == '/') &&
             st.top() != '(') {
        res[cur++] = st.top();
        st.pop();
      }
      st.push(c);
      break;
    case '+':
    case '-':
      while (!st.empty() && st.top() != '(') {
        res[cur++] = st.top();
        st.pop();
      }
      st.push(c);
      break;
    case '(':
      st.push(c);
      break;
    case ')':
      while (st.top() != '(') {
        res[cur++] = st.top();
        st.pop();
      }
      st.pop();
      break;
    default:
      res[cur++] = c;
    }
  }
  while (!st.empty()) {
    res[cur++] = st.top();
    st.pop();
  }
  res[cur] = 0;
  cout << res;

  return 0;
}