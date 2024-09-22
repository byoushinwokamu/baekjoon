#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int opin[300000];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++)
    cin >> opin[i];
  sort(opin, opin + n);
  int summ = 0, cutt = round((double)n * 0.15);
  for (int i = cutt; i < n - cutt; i++)
    summ += opin[i];
  cout << round((double)summ / (n - cutt - cutt));

  return 0;
}