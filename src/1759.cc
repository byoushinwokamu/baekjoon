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

vector<char> ch;
string pw;
int l, c;
int z, m;

void dfs(int depth, int last) {
  if (depth == l) {
    if (z >= 2 && m >= 1)
      cout << pw;
    return;
  }
  for (int i = last + 1; i < c; i++) {
    pw[depth] = ch[i];
    (strchr("aeiou", ch[i]) ? m : z)++;
    dfs(depth + 1, i);
    (strchr("aeiou", ch[i]) ? m : z)--;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> l >> c;
  ch.resize(c);
  pw.resize(l + 1);
  pw[l] = '\n';
  for (int i = 0; i < c; i++)
    cin >> ch[i];

  sort(ch.begin(), ch.end());
  dfs(0, -1);

  return 0;
}
