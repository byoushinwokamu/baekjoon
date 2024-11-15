#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<int> sgs(50); // samgaksu

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  for (int i = 1; i <= 45; i++)
    sgs[i] = sgs[i - 1] + i;
  int n, s = 0;
  cin >> n;
  n--;
  for (int i = 0; i <= 45; i++) {
    s += i;
    if (n < s) {
      cout << (s - n) << ' ' << (n - s + i + 1);
      break;
    }
  }

  return 0;
}
