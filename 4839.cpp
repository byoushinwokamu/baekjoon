#include <climits>
#include <iostream>
#include <vector>

using namespace std;
int prime[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
int coeff[10];
int p[10];
int n, r, l; // n, remainder, level
bool ad;     // additional

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  p[0] = 1, p[1] = 2;
  for (int i = 2; i < 10; i++)
    p[i] = p[i - 1] * prime[i];

  while (true) {
    cin >> r;
    if (!r)
      break;
    cout << r << " = ";

    for (int i = 0; i < 10; i++)
      coeff[i] = 0;
    l = 10;
    ad = false;

    while (r > 0) {
      if (--l == 0) {
        coeff[l] = 1;
        break;
      }
      if (p[l] > r)
        continue;
      coeff[l] = r / p[l];
      r %= p[l];
    }
    for (int i = 0; i < 10; i++) {
      if (coeff[i]) {
        if (ad)
          cout << " + ";
        else
          ad = true;
        cout << coeff[i];
        for (int j = 1; j <= i; j++)
          cout << '*' << prime[j];
      }
    }
    cout << '\n';
  }

  return 0;
}