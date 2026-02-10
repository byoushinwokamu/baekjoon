// BOJ 26123
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  vector<int> height(n);
  for (int i = 0; i < n; i++) cin >> height[i];

  int cur = 0;
  ll laser = 0;
  sort(height.begin(), height.end(), greater<int>());
  for (int day = 0; day < d; day++)
  {
    while (cur < n - 1 && height[cur] == height[cur + 1]) cur++;
    if (height[cur] == 0) break;
    laser += cur + 1;
    height[cur]--;
  }
  cout << laser;

  return 0;
}
