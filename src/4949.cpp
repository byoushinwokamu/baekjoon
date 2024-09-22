#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  char str[101];
  string s;
  getline(cin, s);
  strcpy(str, s.c_str());
  while (strcmp(str, ".")) {
    stack<char> st;
    for (char c : str) {
      if (c == '\0')
        break;
      if (strchr("[]()", c))
        st.push(c);
    }

    /*/ debug
    cout << "stack start\n";
    while (!st.empty()) {
      cout << st.top() << endl;
      st.pop();
    }
    cout << "stack end" << endl;*/

    stack<char> now;
    // int so = 0, de = 0; // count of ), ] not matched

    bool cant = false;
    while (!st.empty()) {
      switch (st.top()) {
      case ']':
        now.push(']');
        // de++;
        break;
      case ')':
        now.push(')');
        // so++;
        break;
      case '[':
        if (!now.empty() && now.top() == ']')
          now.pop();
        else
          cant = true;
        break;
      case '(':
        if (!now.empty() && now.top() == ')')
          now.pop();
        else
          cant = true;
        break;
      }
      st.pop();

      if (cant)
        break;
    }
    if (!cant && now.empty())
      cout << "yes\n";
    else
      cout << "no\n";
    getline(cin, s);
    strcpy(str, s.c_str());
  }

  return 0;
}