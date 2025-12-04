// BOJ 1769
#include <algorithm>
#include <cstring>
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
  char s[1000001];
  cin >> s;
  int cnt = 0;

  while (strlen(s) > 1)
  {
    int n = 0;
    for (int i = 0; i < strlen(s); i++)
      n += s[i] - '0';
    sprintf(s, "%d", n);
    cnt++;
  }
  cout << cnt << '\n'
       << ((s[0] - '0') % 3 ? "NO" : "YES");

  return 0;
}
