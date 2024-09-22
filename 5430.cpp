#include <cstring>
#include <iostream>
#include <list>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t, n;
  char p[100001], xstr[400010];
  list<int> x;

  cin >> t;
  for (int i = 0; i < t; i++) {
    strcpy(p, "");
    strcpy(xstr, "");
    cin >> p >> n;
    cin >> xstr;
    int xint;
    char *xptr = strtok(xstr + 1, ",");
    for (int j = 0; j < n; j++) {
      x.push_back(atoi(xptr));
      xptr = strtok(NULL, ",");
    }

    bool reverse = false, error = false;
    int func = strlen(p);
    for (int j = 0; j < func; j++) {
      switch (p[j]) {
      case 'R':
        reverse = !reverse;
        break;
      case 'D':
        if (x.empty())
          error = true;
        else if (!reverse)
          x.pop_front();
        else
          x.pop_back();
        break;
      }
      if (error)
        break;
    }

    if (error)
      cout << "error\n";
    else if (x.empty())
      cout << "[]\n";
    else {
      if (!reverse) {
        list<int>::iterator iter = x.begin();
        cout << '[' << *iter;
        for (iter++; iter != x.end(); iter++)
          cout << ',' << *iter;
        cout << "]\n";
      } else {
        list<int>::reverse_iterator iter = x.rbegin();
        cout << '[' << *iter;
        for (iter++; iter != x.rend(); iter++)
          cout << ',' << *iter;
        cout << "]\n";
      }
    }
    x.clear();
  }

  return 0;
}