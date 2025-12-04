// BOJ 23841
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
  int r, c;
  cin >> r >> c;

  string s;
  while (r--)
  {
    cin >> s;
    for (int i = 0; i < c / 2; i++)
      if (s[i] != '.') s[c - i - 1] = s[i];
      else if (s[c - i - 1] != '.') s[i] = s[c - i - 1];
    cout << s << '\n';
  }

  return 0;
}
