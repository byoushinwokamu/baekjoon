#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int i = 0;
  string s;
  while (true) {
    getline(cin, s);
    if (s[0] == '0')
      break;
    cout << "Case " << ++i << ": Sorting... done!\n";
  }

  return 0;
}