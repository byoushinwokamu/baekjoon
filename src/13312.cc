// BOJ 13312
#include <cassert>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int LIM = 1000000000;

typedef long long ll;

float _abs(float x) { return x < 0 ? -x : x; }
bool is_equal(double a, double b) { return _abs(a - b) < 1e-3; }

int main()
{
  int N, a;
  ll tot = 0;
  double x = 0;
  assert(scanf("%d", &N) == 1);
  assert(2 <= N && N <= 100000);
  for (int i = 1; i <= N; i++)
  {
    assert(scanf("%d", &a) == 1);
    tot += a;
    x += a / 100.0;
  }
  assert(-100 <= tot && tot <= 100);
  cout << x << ' ' << acos(x) << endl
       << tot / 100.0 << ' ' << acos(tot / 100.0) << endl;
  assert(!is_equal(acos(x), acos(tot / 100.0)));
  return 0;
}
