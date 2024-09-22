#include <iostream>
#include <list>
#include <string>

using namespace std;

string str;
string bom;
int ls, lb;
list<char> li;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> str >> bom;
  for (char c : str)
    li.push_back(c);
  ls = str.length();
  lb = bom.length();

  auto cur = li.begin();
  int cn = 0;
  while (cn + lb <= ls) {
    auto it = cur;
    bool same = true;

    for (int i = 0; i < lb; i++, it++) {
      if (*it != bom[i]) {
        same = false;
        break;
      }
    }
    if (same) {
      cur = li.erase(cur, it);
      for (int i = 0; i < lb; i++)
        cur--;
      cn -= lb;
      ls -= lb;
    } else {
      cur++;
      cn++;
    }
  }

  if (li.empty())
    cout << "FRULA";
  else
    for (auto c : li)
      cout << c;

  return 0;
}