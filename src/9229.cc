// BOJ 9229
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
  string sa, sb;
  while (true)
  {
    sa = sb;
    cin >> sb;
    if (sa == "#" && sb == "#") break;
    bool cor = true;

    while (true)
    {
      sa = sb;
      cin >> sb;
      if (sb == "#") break;

      if (sa.size() != sb.size())
      {
        cor = false;
        continue;
      }

      int cnt = 0;
      int sz = min(sa.size(), sb.size());
      for (int i = 0; i < sz; i++)
        if (sa[i] != sb[i]) cnt++;
      if (cnt != 1) cor = false;
    }

    cout << (cor ? "Correct\n" : "Incorrect\n");
  }

  return 0;
}
