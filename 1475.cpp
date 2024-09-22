#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int arr[10] = {
      0,
  };
  while (n) {
    arr[n % 10]++;
    n /= 10;
  }

  int max = 0;
  arr[6] += arr[9];
  if (arr[6] % 2)
    arr[6]++;
  arr[6] /= 2;
  arr[9] = arr[6];
  for (int i = 0; i < 10; i++)
    max = max > arr[i] ? max : arr[i];
  cout << max;
}