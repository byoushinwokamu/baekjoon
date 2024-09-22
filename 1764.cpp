#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  set<string> nohear;
  set<string> nohearsee;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    nohear.insert(s);
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (nohear.count(s))
      nohearsee.insert(s);
  }
  cout << nohearsee.size() << '\n';
  for (auto i : nohearsee)
    cout << i << '\n';

  return 0;
}