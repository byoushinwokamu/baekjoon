// BOJ 32753
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
  int n, k;
  cin >> n >> k;
  if (n == 1)
    for (int i = 0; i < k; i++) cout << "1 ";
  else if (k == 1 && n == 2) cout << "1 2";
  else
    cout << -1;

  return 0;
}
