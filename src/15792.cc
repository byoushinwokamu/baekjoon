// BOJ 15792
#include <iostream>
using namespace std;
int main()
{
  long long a, b, ex = 0;
  cin >> a >> b;

  if (a < b)
  {
    cout << "0.";
    while (a < b) a *= 10, ex--;
  }
  else
    while (a >= b * 10) b *= 10, ex++;

  for (int j = 1; j < -ex; j++)
    cout << '0';
  for (int i = 0; i < 8; i++)
  {
    cout << endl
         << a << ' ' << b << endl
         << a / b;
    // cout << a / b;
    a %= b;

    if (ex > 0)
      b /= 10, ex--;
    else
    {
      if (a % 10 && a > b * 10)
        a *= 10;

      if (!ex--)
        cout << '.';
    }

    // if (a == 0)
    //   break;
  }
  for (ex; ex >= 0; ex--)
    cout << '0';

  return 0;
}
