#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (a == c)
    cout << e;
  else if (c == e)
    cout << a;
  else
    cout << c;
  cout << " ";
  if (b == d)
    cout << f;
  else if (d == f)
    cout << b;
  else
    cout << d;

  return 0;
}