#include <iostream>

using namespace std;

int arr[1001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  arr[1] = 1;
  arr[2] = 3;
  for (int i = 3; i <= 1000; i++)
    arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
  cin >> n;
  cout << arr[n];

  return 0;
}