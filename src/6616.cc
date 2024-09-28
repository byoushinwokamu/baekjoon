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

    vector<char> v(s.length());
    int len = s.length() / n;
    for (int i = 0; i < s.length(); i++) {
      v[i] = s[(i % n) * (len) + (i / n)];
    }
    for (auto a : v)
      cout << a;
    cout << '\n';

    cin >> n;
  }

  return 0;
}