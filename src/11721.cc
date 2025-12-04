// BOJ 11721
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
  string s;
  cin >> s;
  int i = 0;
  for (auto c : s)
  {
    cout << c;
    if (++i == 10) i = 0, cout << '\n';
  }

  return 0;
}
