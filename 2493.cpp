#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  vector<int> tower;
  vector<int> result(500000);
  stack<pair<int, int>> raser; // height, index

  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    tower.push_back(t);
  }

  vector<int>::reverse_iterator iter;
  int now = n;
  for (iter = tower.rbegin(); iter != tower.rend(); iter++) {
    if (raser.empty())
      raser.push(make_pair(*iter, now));
    else if (raser.top().first > *iter)
      raser.push(make_pair(*iter, now));
    else {
      while (!raser.empty() && raser.top().first < *iter) {
        result[raser.top().second - 1] = now;
        raser.pop();
      }
      raser.push(make_pair(*iter, now));
    }
    now--;
  }
  while (!raser.empty()) {
    result.push_back(0);
    raser.pop();
  }

  for (int i = 0; i < n; i++)
    cout << result[i] << " ";

  return 0;
}