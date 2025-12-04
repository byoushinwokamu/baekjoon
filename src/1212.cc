// BOJ 1212
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
  string s, d;
  cin >> s;
  if (s == "0")
  {
    cout << "0";
    return 0;
  }
  for (auto it = s.rbegin(); it != s.rend(); it++)
  {
    switch (*it - '0')
    {
    case 0:
      d.append("000");
      break;
    case 1:
      d.append("100");
      break;
    case 2:
      d.append("010");
      break;
    case 3:
      d.append("110");
      break;
    case 4:
      d.append("001");
      break;
    case 5:
      d.append("101");
      break;
    case 6:
      d.append("011");
      break;
    case 7:
      d.append("111");
      break;
    }
  }

  bool start = false;
  for (auto it = d.rbegin(); it != d.rend(); it++)
    if (start)
      cout << *it;
    else if (*it == '1')
    {
      cout << *it;
      start = true;
    }
  return 0;
}
