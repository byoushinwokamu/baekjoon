#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t = 1, l;
  string s;
  bool ctn = false;
  while (true) {
    ctn = false;
    cin >> s;
    if (s == "0")
      break;
    cout << t++ << ". ";
    l = s.length();
    if (s[0] != '1') {
      cout << "NOT\n";
      continue;
    }
    for (int i = 1; i < l - 1; i++) {
      switch (s[i] - '0') {
      case 1:
      case 2:
        ctn = true;
        break;
      case 3:
        if (s[i - 1] != '4' && s[i - 1] != '6')
          ctn = true;
        break;
      case 4:
      case 5:
        if (s[i - 1] != '1' && s[i - 1] != '3')
          ctn = true;
        break;
      case 6:
      case 7:
        if (s[i - 1] != '8')
          ctn = true;
        break;
      case 8:
        if (s[i - 1] != '5' && s[i - 1] != '7')
          ctn = true;
        break;
      }
      if (ctn)
        break;
    }
    if (ctn)
      cout << "NOT\n";
    else if (s[l - 1] == '2' && (s[l - 2] == '4' || s[l - 2] == '6'))
      cout << "VALID\n";
    else
      cout << "NOT\n";
  }

  return 0;
}
