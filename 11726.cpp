#include <iostream>

using namespace std;

long long arr[1001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= 1000; i++)
    arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
  int n;
  cin >> n;
  cout << (arr[n] % 10007);

  return 0;
}