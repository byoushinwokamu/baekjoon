#include <iostream>

using namespace std;
int n, m;
int arr[8];
bool used[9];

void dfs(int depth) {
  if (depth == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << '\n';
  } else {
    int i = depth == 0 ? 1 : arr[depth - 1];
    for (; i <= n; i++) {
      if (used[i])
        continue;
      arr[depth] = i;
      used[i] = true;
      dfs(depth + 1);
      used[i] = false;
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  dfs(0);
  return 0;
}