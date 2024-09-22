#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[8];
int num[8];
int used[8];
void dfs(int depth, int st) {
  if (depth == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << '\n';
    return;
  }
  int i = st;
  for (; i < n; i++) {
    if (i > 0 && num[i] == num[i - 1] && !used[i - 1])
      continue;
    arr[depth] = num[i];
    used[i] = 1;
    dfs(depth + 1, i + 1);
    used[i] = 0;
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  sort(num, num + n);
  dfs(0, 0);

  return 0;
}