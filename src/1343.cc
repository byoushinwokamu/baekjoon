// BOJ 1343
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
  int c = 0;
  cin >> s;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'X')
      c++;
    if (i == s.length() - 1 || s[i + 1] == '.')
    {
      if (c % 4 == 0)
        for (int j = i - c + 1; j <= i; j++)
          s[j] = 'A';
      else if (c % 2 == 0)
      {
        for (int j = i - c + 1; j <= i - 2; j++)
          s[j] = 'A';
        s[i - 1] = s[i] = 'B';
      }
      else
      {
        cout << -1;
        return 0;
      }

      c = 0;
    }
  }
  cout << s;

  return 0;
}
