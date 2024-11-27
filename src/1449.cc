#include <algorithm>
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
  int n, l;
  cin >> n >> l;
  vector<int> hole(n);

  for (int i = 0; i < n; i++)
    cin >> hole[i];
  sort(hole.begin(), hole.end());

  int tape = 0, bef = 0;
  for (int i = 0; i < n; i++) {
    if (bef <= hole[i]) {
      bef = hole[i] + l;
      tape++;
    }
  }
  cout << tape;

  return 0;
}
