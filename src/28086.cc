#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  ll a = 0, b = 0, c = 0, res = 0;
  char op;
  bool minus = false;

  if (s[c] == '-')
    minus = true, c++;
  while (s[c] >= '0') {
    a *= 8;
    a += s[c++] - '0';
  }
  op = s[c++];
  if (minus)
    a = -a;

  if (s[c] == '-')
    minus = true, c++;
  else
    minus = false;
  while (c < s.length()) {
    b *= 8;
    b += s[c++] - '0';
  }
  if (minus)
    b = -b;

  switch (op) {
  case '+':
    res = a + b;
    break;
  case '-':
    res = a - b;
    break;
  case '*':
    res = a * b;
    break;
  case '/':
    if (b == 0) {
      cout << "invalid";
      return 0;
    }
    if (a * b > 0)
      res = a / b;
    else {
      if (a < 0)
        a = -a, b = -b;
      while (a > 0)
        a += b, res--;
    }
    // if (res < 0 && a % -b != 0)
    //   res--;
  }

  if (res < 0)
    minus = true, res = -res;
  else if (res == 0) {
    cout << '0';
    return 0;
  } else
    minus = false;

  stack<char> st;
  while (res > 0) {
    st.push(res % 8 + '0');
    res /= 8;
  }

  if (minus)
    cout << '-';
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }

  return 0;
}