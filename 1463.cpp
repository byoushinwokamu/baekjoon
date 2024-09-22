#include <iostream>

using namespace std;

int arr[3000001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 2; i <= 1000000; i++)
    arr[i] = 99999999;
  for (int i = 1; i <= 1000000; i++) {
    arr[i * 3] = arr[i] + 1;
    arr[i * 2] = arr[i * 2] < arr[i] + 1 ? arr[i * 2] : arr[i] + 1;
    arr[i + 1] = arr[i + 1] < arr[i] + 1 ? arr[i + 1] : arr[i] + 1;
  }
  cout << arr[n];

  return 0;
}