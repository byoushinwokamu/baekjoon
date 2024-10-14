#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 1; i <= n; i++)
    d.push_back(i);
  while (d.size() > 1) {
    cout << d.front() << ' ';
    d.pop_front();
    d.push_back(d.front());
    d.pop_front();
  }
  cout << d.front() << ' ';

  return 0;
}
