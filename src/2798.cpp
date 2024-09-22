#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  int arr[100];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int max = 0;
  for (int i = 0; i < n - 2; i++)
    for (int j = i + 1; j < n - 1; j++)
      for (int k = j + 1; k < n; k++) {
        int t = arr[i] + arr[j] + arr[k];
        if (t <= m)
          max = max > t ? max : t;
      }

  cout << max;

  return 0;
}