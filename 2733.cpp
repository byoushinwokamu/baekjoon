#include <iostream>
#include <stack>
#include <string>
#include <vector>
// 시간초과
using namespace std;
string op;
string temp;
string res;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "PROGRAM #" << tt << ":\n";

    int ptr = 0;
    vector<int> reg(32768);
    stack<int> lst;
    bool err = false;
    op = "";
    temp = "";
    res = "";

    while (temp != "end") {
      getline(cin, temp);
      int juseok = temp.find('%');
      if (juseok != string::npos)
        temp = temp.substr(0, juseok);
      op.append(temp);
    }

    int len = op.length() - 3;
    for (int i = 0; i < len; i++) {
      switch (op[i]) {
      case '[':
        if (reg[ptr] == 0) {
          while (i < len && op[i] != ']')
            i++;
          if (i == len)
            err = true;
        } else
          lst.push(i);
        break;
      case ']':
        if (lst.empty())
          err = true;
        else if (reg[ptr] != 0)
          i = lst.top();
        else
          lst.pop();
        break;

      case '+':
        reg[ptr] += reg[ptr] == 255 ? -255 : 1;
        break;
      case '-':
        reg[ptr] -= reg[ptr] == 0 ? -255 : 1;
        break;
      case '>':
        ptr += ptr == 32767 ? -32767 : 1;
        break;
      case '<':
        ptr -= ptr == 0 ? -32767 : 1;
        break;
      case '.':
        res.append(1, static_cast<char>(reg[ptr]));
        break;
      } // switch

      if (err)
        break;
    } // for opstr

    if (!lst.empty() || err)
      cout << "COMPILE ERROR\n";
    else
      cout << res << '\n';
  } // for testcase

  return 0;
}