#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int a, b;
  switch (n) {
  case 1:
    a = 12, b = 1600;
    break;
  case 2:
    a = 11, b = 894;
    break;
  case 3:
    a = 11, b = 1327;
    break;
  case 4:
    a = 10, b = 1311;
    break;
  case 5:
    a = 9, b = 1004;
    break;
  case 6:
    a = 9, b = 1178;
    break;
  case 7:
    a = 9, b = 1357;
    break;
  case 8:
    a = 8, b = 837;
    break;
  case 9:
    a = 7, b = 1055;
    break;
  case 10:
    a = 6, b = 556;
    break;
  case 11:
    a = 6, b = 773;
  }
  cout << a << ' ' << b;

  return 0;
}