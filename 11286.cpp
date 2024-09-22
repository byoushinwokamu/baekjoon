#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct compare {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b))
      return a > b;
    else
      return abs(a) > abs(b);
  }
};

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n;
  priority_queue<int, vector<int>, compare> pq;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0) {
      if (pq.empty()) {
        cout << "0\n";
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(x);
    }
  }

  return 0;
}