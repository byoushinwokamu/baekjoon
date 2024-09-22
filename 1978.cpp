#include <iostream>

using namespace std;

int noprime[1001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int arr[100];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int cnt = 0;
  noprime[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    if (!noprime[i]) {
      for (int j = 2; j * i <= 1000; j++)
        noprime[j * i] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    cnt += noprime[arr[i]] - 1;
  cout << -cnt;
  return 0;
}