#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 1)
    n = 0;
  else
    n = (n - 2) / 6 + 1;
  int sum = 0;
  int i;
  for (i = 1; sum < n; i++)
    sum += i;
  cout << i;

  return 0;
}