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

int n;
int nog;
string s;
vector<int> gg;

int dfs(int dep) {
  if (dep == nog) {
    stack<char> st;
    for (auto c : s) {
      if (c == '(')
        st.push('(');
      else if (st.empty())
        return 1;
      else
        st.pop();
    }
    if (!st.empty())
      return 1;
    cout << s;
    return 0;
  } else {
    s[gg[dep++]] = '(';
    if (!dfs(dep))
      return 0;
    s[gg[dep - 1]] = ')';
    if (!dfs(dep))
      return 0;
    s[gg[--dep]] = 'G';
    return 1;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'G')
      gg.push_back(i), nog++;
  dfs(0);

  return 0;
}
