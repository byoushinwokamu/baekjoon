#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, c = 0;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vector<int> v(26);
    auto it = s.begin();
    v[*it - 'a']++;
    bool gr = true;
    for (it++; it != s.end(); it++) {
      if ((*(it - 1) != *it) && v[*it - 'a']) {
        gr = false;
        break;
      }
      v[*it - 'a']++;
    }
    if (gr)
      c++;
  }
  cout << c;
  return 0;
}