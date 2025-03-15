// BOJ 10820
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string str;
  getline(cin, str);
  while (!cin.eof()) {
    int l = 0, u = 0, n = 0, s = 0;
    for (auto c : str) {
      if (c >= 'A' && c <= 'Z')
        u++;
      else if (c >= 'a' && c <= 'z')
        l++;
      else if (c >= '0' && c <= '9')
        n++;
      else if (c == ' ')
        s++;
    }
    cout << l << ' ' << u << ' ' << n << ' ' << s << '\n';
    getline(cin, str);
  }

  return 0;
}
