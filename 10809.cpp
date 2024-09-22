#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  vector<int> v(26, -1);
  for (int i = 0; i < s.length(); i++) {
    int n = static_cast<int>(s[i]) - 97;
    if (v[n] == -1)
      v[n] = i;
  }
  for (int i = 0; i < 26; i++) {
    cout << v[i] << " ";
  }

  return 0;
}