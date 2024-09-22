#include <cstring>
#include <iostream>
#include <list>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  char op[1000001];
  cin >> t;

  for (int j = 0; j < t; j++) {
    list<char> li;
    cin >> op;
    int n = strlen(op);
    list<char>::iterator iter = li.end();
    for (int i = 0; i < n; i++) {
      switch (op[i]) {
      case '<':
        if (iter != li.begin())
          iter--;
        break;
      case '>':
        if (iter != li.end())
          iter++;
        break;
      case '-':
        if (iter != li.begin())
          iter = li.erase(--iter);
        break;
      default:
        li.insert(iter, op[i]);
        break;
      }
    }
    for (iter = li.begin(); iter != li.end(); iter++)
      cout << *iter;
    cout << '\n';
  }
}