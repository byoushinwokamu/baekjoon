#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (auto it = s.rbegin(); it != s.rend(); it++)
      cout << *it;
    cout << '\n';
  }

  return 0;
}