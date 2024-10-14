#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, nx;
  double x;
  cin >> n >> x;
  nx = x * 100;
  int pp = 0, sc = 0, p, c;
  string s;
  for (int i = 0; i < n - 1; i++) {
    cin >> p >> s;
    switch (s[0]) {
    case 'A':
      c = 400;
      break;
    case 'B':
      c = 300;
      break;
    case 'C':
      c = 200;
      break;
    case 'D':
      c = 100;
      break;
    default:
      c = 0;
    }
    c += (s[1] == '+' ? 50 : 0);
    sc += p * c;
    pp += p;
  }
  cin >> p;
  nx *= (pp + p);
  switch ((nx - sc) / pp / 50) {
  case 9:
    cout << "A+";
    break;
  case 8:
    cout << "A0";
    break;
  case 7:
    cout << "A+";
    break;
  case 6:
    cout << "A0";
    break;
  case 5:
    cout << "A+";
    break;
  case 4:
    cout << "A0";
    break;
  case 3:
    cout << "A+";
    break;
  case 2:
    cout << "A0";
    break;
  case 1:
    cout << "A+";
    break;
  case 0:
    cout << "A0";
    break;
  }
  cout << (nx - sc) / pp / 50 << endl;

  return 0;
}
