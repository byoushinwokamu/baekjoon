#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  char str[101];
  int n;
  cin >> n;
  cin >> str;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += str[i] - 48;
  }
  cout << sum;
  return 0;
}