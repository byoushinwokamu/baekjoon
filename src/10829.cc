// BOJ 10829
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
  ll n;
  string s;
  cin >> n;
  if (!n)
  {
    cout << 0;
    return 0;
  }
  while (n)
  {
    s.append(n % 2 ? "1" : "0");
    n /= 2;
  }
  for (auto i = s.rbegin(); i != s.rend(); i++)
    cout << *i;

  return 0;
}
