// BOJ 6616
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  string s;
  string::iterator a;
  cin >> n;
  while (n > 0) {
    cin.ignore();
    getline(cin, s);
    while ((a = find(s.begin(), s.end(), ' ')) != s.end())
      s.erase(a);
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    string v;
    v.resize(s.length());
    int cur = 0;
    int cycle = 0;
    for (int i = 0; i < s.length(); i++) {
      v[cur] = s[i];
      cur += n;
      if (cur >= v.length())
        cur = ++cycle;
    }
    cout << v << '\n';

    cin >> n;
  }

  return 0;
}