// BOJ 15881
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
  int n, c = 0;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n - 3; i++)
    if (s[i] == 'p' && s[i + 1] == 'P' && s[i + 2] == 'A' && s[i + 3] == 'p') c++, i += 3;

  cout << c;

  return 0;
}
