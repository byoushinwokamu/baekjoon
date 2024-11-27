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

int cur = 0;
stack<int> gh;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s;
  int sr = 0;
  bool topop = false;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    switch (s[i]) {
    case '(':
      gh.push(0);
      break;
    case ')':
      topop = true;
      break;
    case 'H':
      if (gh.empty())
        sr += 1;
      else
        gh.top() += 1;
      break;
    case 'C':
      gh[cur] += 12;
      break;
    case 'O':
      gh[cur] += 16;
      break;
    default:
      switch (s[i - 1]) {
      case 'H':
        gh[cur] += 1 * (s[i] - '0');
        break;
      case 'C':
        gh[cur] += 12 * (s[i] - '0');
        break;
      case 'O':
        gh[cur] += 16 * (s[i] - '0');
        break;
      }
    }
  }
  cout << gh[0];

  return 0;
}
