#include <iostream>

using namespace std;

int arr[10001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr[a]++;
  }
  for (int i = 1; i <= 10000; i++)
    for (int j = 0; j < arr[i]; j++)
      cout << i << '\n';
  return 0;
}