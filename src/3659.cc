#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int tc;
  int h, l;
  int a, b;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    cin >> h >> l;
    vector<pair<int, int>> car(2501);
    vector<int> belt(h);
    int cnt = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < l; j++) {
        cin >> a;
        if (a > 0)
          car[a] = {i, j}, cnt++;
      }
    }
    long long time = 0;
    for (int i = 1; i <= cnt; i++) {
      time += (car[i].first) * 20;
      b = abs(belt[car[i].first] - car[i].second);
      time += min(b, l - b) * 5;
      belt[car[i].first] = car[i].second;
    }
    cout << time << '\n';
  }

  return 0;
}