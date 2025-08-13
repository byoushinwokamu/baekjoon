// BOJ 14626
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
  int sum = 0;
  bool odd = false;
  cin >> s;
  for (int i = 0; i < 13; i++)
  {
    if (s[i] == '*')
      odd = i % 2;
    else
      sum += (s[i] - '0') * (i % 2 ? 3 : 1);
  }
  for (int i = 0; i <= 9; i++)
    if ((sum + i * (odd ? 3 : 1)) % 10 == 0)
    {
      cout << i;
      break;
    }
  return 0;
}
