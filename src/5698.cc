#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

char up(char c) { return c >= 'a' ? c - 32 : c; }

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s;
  getline(cin, s);
  while (s[0] != '*') {
    char st = up(s[0]);
    bool ta = true;
    for (int i = 1; i < s.length() - 1; i++) {
      if (s[i] == ' ' && up(s[i + 1]) != st)
        ta = false;
    }
    cout << (ta ? "Y\n" : "N\n");
    getline(cin, s);
  }

  return 0;
}
