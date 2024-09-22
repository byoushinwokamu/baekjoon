#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[8];
int num[8];

void dfs(int depth, int st) {
  if (depth == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << '\n';
    return;
  }
  for (int i = st; i < n; i++) {
    arr[depth] = num[i];
    dfs(depth + 1, i);
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
  dfs(0, 0);

  return 0;
}