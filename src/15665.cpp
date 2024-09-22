#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[7];
int num[7];
int used[7];
void dfs(int depth) {
  if (depth == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    arr[depth] = num[i];
    used[i] = 1;
    dfs(depth + 1);
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
  n = unique(num, num + n) - num;
  dfs(0);

  return 0;
}