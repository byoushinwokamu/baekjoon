#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  string s, dict[20];
  int n;
  cin >> s >> n;
  for (int i = 0; i < n; i++)
    cin >> dict[i];

  int len = s.length();
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < len; j++)
      s[j] = (s[j] - '`') % 26 + 'a';
    for (int j = 0; j < n; j++) {
      if (s.find(dict[j]) != s.npos) {
        cout << s;
        return 0;
      }
    }
  }

  return 0;
}