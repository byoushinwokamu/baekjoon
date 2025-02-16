// BOJ 32953
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  map<int, int> stu;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int s;
      cin >> s;
      if (stu.find(s) != stu.end()) {
        stu[s]++;
      } else {
        stu.insert({s, 1});
      }
    }
  }
  int cnt = 0;
  for (auto s : stu) {
    if (s.se >= m)
      cnt++;
  }
  cout << cnt;

  return 0;
}
