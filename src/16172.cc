// BOJ 16172
#include <algorithm>
#include <cctype>
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
  string str, s, k;
  bool yes = false;
  cin >> str >> k;

  for (auto c : str)
    if (isalpha(c)) s.push_back(c);

  int sc, kc;
  int sl = s.length(), kl = k.length();
  for (sc = 0; sc <= sl - kl; sc++)
  {
    for (kc = 0; kc < kl; kc++)
    {
      if (sc + kc >= sl)
        break;

      if (s[sc + kc] != k[kc]) break;

      if (kc == kl - 1)
      {
        yes = true;
        break;
      }
    }
    if (yes) break;
  }

  cout << (yes ? 1 : 0);
  return 0;
}
