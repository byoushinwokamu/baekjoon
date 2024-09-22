#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;
bool compare(const P &p1, const P &p2) {
  if (p1.first != p2.first)
    return p1.first - p2.first < 0 ? true : false;
  return p1.second - p2.second < 0 ? true : false;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  vector<P> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int xi, yi;
    cin >> xi >> yi;
    v.push_back(make_pair(xi, yi));
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " " << v[i].second << "\n";
  }

  return 0;
}