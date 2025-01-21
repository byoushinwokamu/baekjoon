// 25370 카드 숫자 곱의 경우의 수
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

set<int> aa;
int a = 1;
int n;

void dfs(int depth) {
  if (depth == n)
    return;
  for (int i = 1; i < 10; i++) {
    a *= i;
    if (aa.find(a) == aa.end())
      aa.insert(a);
    dfs(depth + 1);
    a /= i;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  dfs(0);
  cout << aa.size();

  return 0;
}
