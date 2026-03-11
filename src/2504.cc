// BOJ 2504
#include <algorithm>
#include <iostream>
#include <stack>
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

  int acc = 0;
  stack<char> gh;
  stack<int> val;

  for (auto c : s)
  {
    switch (c)
    {
    case '(':
    case '[':
      gh.push(c);
      break;
    case ')':
      if (gh.top() != '(')
      {
        cout << 0;
        return 0;
      }
      gh.pop();
      break;
    case ']':
      if (gh.top() != '[')
      {
        cout << 0;
        return 0;
      }
      gh.pop();
      break;
    }
  }
  if (!gh.empty())
  {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < s.length(); i++)
  {
    switch (s[i])
    {
    case '(':
      gh.push(s[i]);
      val.push(1);
      break;
    case '[':
      gh.push(s[i]);
      val.push(1);
      break;
    case ')':
      break;
    case ']':
      break;
    }
  }

  return 0;
}
