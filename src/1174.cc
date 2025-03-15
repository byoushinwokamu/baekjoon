// BOJ 1174
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<ll> jul;
int n;
ll t;

void dfs(int level) {
  int digit = t ? t % 10 : 10;
  if (level == 0) {
    for (int i = 0; i < digit; i++)
      jul.push_back(t * 10 + i);
    return;
  }

  t *= 10;
  for (int i = 1; i < digit; i++) {
    t += i;
    dfs(level - 1);
    t -= i;
  }
  t /= 10;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;

  for (int i = 0; i < 9; i++)
    dfs(i);
  jul.push_back(9876543210);

  if (jul.size() >= n)
    cout << jul[n - 1];
  else
    cout << -1;

  return 0;
}
