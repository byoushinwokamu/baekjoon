#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;
bool compare(const P &p1, const P &p2) {
  return p1.second != p2.second ? p1.second < p2.second : p1.first < p2.first;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<P> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end(), compare);
  for (auto i = v.begin(); i != v.end(); i++)
    cout << i->first << " " << i->second << "\n";

  return 0;
}