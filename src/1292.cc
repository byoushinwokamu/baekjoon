// BOJ 1292
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
  int a, b, c = 1;
  cin >> a >> b;
  vector<int> v(b + 1);
  for (int i = 1; i <= b; i++)
  {
    for (int j = 0; i <= b && j < c; i++, j++)
      v[i] = c;
    i--, c++;
  }

  int s = 0;
  for (int i = a; i <= b; i++)
    s += v[i];
  cout << s;

  return 0;
}
