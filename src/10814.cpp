#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<pair<int, int>, string> p1, pair<pair<int, int>, string> p2) {
  return (p1.first.first - p2.first.first != 0
              ? p1.first.first < p2.first.first
              : p1.first.second < p2.first.second);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<pair<int, int>, string>> v;
  int ag;
  string na;
  for (int i = 0; i < n; i++) {
    cin >> ag >> na;
    v.push_back(make_pair(make_pair(ag, i), na));
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << v[i].first.first << " " << v[i].second << "\n";
  }

  return 0;
}