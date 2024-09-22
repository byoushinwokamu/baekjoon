#include <cstring>
#include <iostream>
#include <list>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  list<char> li;
  int n, m;
  char str[100001];
  cin >> str >> m;
  n = strlen(str);

  for (int i = 0; i < n; i++)
    li.push_back(str[i]);

  list<char>::iterator iter = li.end();
  char op;
  for (int i = 0; i < m; i++) {
    cin >> op;
    switch (op) {
    case 'L':
      if (iter != li.begin())
        iter--;
      break;
    case 'D':
      if (iter != li.end())
        iter++;
      break;
    case 'B':
      if (iter != li.begin())
        iter = li.erase(--iter);
      break;
    case 'P':
      cin >> op;
      li.insert(iter, op);
      break;
    }
  }
  for (iter = li.begin(); iter != li.end(); iter++)
    cout << *iter;
}