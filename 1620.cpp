#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  unordered_map<string, int> umap;
  vector<string> v;
  string s;
  char key[21];
  for (int i = 1; i <= n; i++) {
    cin >> s;
    umap.insert(make_pair(s, i));
    v.push_back(s);
  }
  for (int i = 0; i < m; i++) {
    cin >> key;
    if (strchr("1234567890", key[0]))
      cout << v[atoi(key) - 1] << '\n';
    else {
      s = key;
      auto it = umap.find(s);
      cout << (*it).second << '\n';
    }
  }

  return 0;
}