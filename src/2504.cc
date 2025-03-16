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

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int v;
  string s;
  cin >> s;
  int sum = 0;
  stack<char> gh;
  stack<int> val;
  for (auto c : s) {
    switch (c) {
    case '(':
      gh.push(c);
      val.push(2);
      break;
    case '[':
      gh.push(c);
      val.push(3);
      break;
    case ')':
      if (gh.empty() || gh.top() != '(') {
        cout << 0;
        return 0;
      }
      gh.pop();
      break;
    }
  }
  if (!gh.empty() || !val.empty()) {
    cout << 0;
    return 0;
  }

  return 0;
}
