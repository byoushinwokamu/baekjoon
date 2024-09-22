#include <iostream>
#include <stack>
#include <string>

using namespace std;
string str, bom;
stack<char> stll, strr;
int bcnt, bcur;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> str >> bom;
  const int slen = str.length(), blen = bom.length();
  for (char c : str)
    stll.push(c);

  bcur = blen - 1;
  while (!stll.empty()) {
    if (stll.top() == bom[bcur])
      bcur--;
    else if (bcur != blen - 1) {
      bcur = blen - 1;
      continue;
    } else
      bcur = blen - 1;
    strr.push(stll.top());
    stll.pop();
    if (bcur == -1) {
      for (int i = 0; i < blen; i++)
        strr.pop();
      for (int i = 0; i < blen && !strr.empty(); i++) {
        stll.push(strr.top());
        strr.pop();
      }
      bcur = blen - 1;
    }
  }

  if (strr.empty())
    cout << "FRULA";
  else
    while (!strr.empty())
      cout << strr.top(), strr.pop();

  return 0;
}