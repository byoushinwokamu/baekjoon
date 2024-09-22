#include <iostream>

using namespace std;

int fibo0[41];
int fibo1[41];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  fibo0[0] = 1;
  fibo1[1] = 1;
  for (int i = 2; i <= 40; i++) {
    fibo0[i] = fibo0[i - 1] + fibo0[i - 2];
    fibo1[i] = fibo1[i - 1] + fibo1[i - 2];
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << fibo0[n] << " " << fibo1[n] << '\n';
  }

  return 0;
}