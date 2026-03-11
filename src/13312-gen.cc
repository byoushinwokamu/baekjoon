// BOJ 13312-gen
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  cout << "100000\n";
  for (int i = 0; i < 499; i++)
  {
    for (int j = 0; j < 100; j++)
      cout << "13 ";
    for (int j = 0; j < 100; j++)
      cout << "-13 ";
  }
  for (int j = 0; j < 100; j++)
    cout << "2 ";
  for (int j = 0; j < 100; j++)
    cout << "-1 ";
  cout << endl;
  return 0;
}