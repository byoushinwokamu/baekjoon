// BOJ 32172
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, a = 0;
  cin >> n;
  unordered_set<int> us;
  us.insert(0);

  for (int i = 1; i <= n; i++)
    if (a - i < 0 || us.find(a - i) != us.end()) a += i, us.insert(a);
    else a -= i, us.insert(a);

  cout << a;

  return 0;
}
