#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> conf;
bool compare(conf c1, conf c2) {
  return c1.second == c2.second ? c1.first < c2.first : c1.second < c2.second;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, s, f;
  cin >> n;
  vector<conf> v;
  for (int i = 0; i < n; i++) {
    cin >> s >> f;
    v.push_back(make_pair(s, f));
  }
  sort(v.begin(), v.end(), compare);
  int now = 0, cnt = 0;
  for (conf i : v) {
    if (i.first >= now) {
      now = i.second;
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}