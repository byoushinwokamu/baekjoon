// BOJ 13314-gen
#include <iostream>
using namespace std;
int main()
{
  cout << 100 << '\n';
  for (int i = 1; i <= 99; i++)
  {
    for (int j = 1; j <= 99; j++)
    {
      if (i == j) cout << "0 ";
      else cout << "10 ";
    }
    if (i == 100) cout << "0\n";
    else cout << "1 \n";
  }
  for (int j = 1; j <= 99; j++)
    cout << "1 ";
  cout << "0\n";
  return 0;
}