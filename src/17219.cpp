#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  map<string, string> notepad;
  for (int i = 0; i < n; i++) {
    string site, pass;
    cin >> site >> pass;
    notepad.insert(make_pair(site, pass));
  }
  for (int i = 0; i < m; i++) {
    string site;
    cin >> site;
    cout << notepad[site] << '\n';
  }

  return 0;
}