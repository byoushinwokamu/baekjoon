// BOJ 16478
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  double ab, bc, cd;
  cin >> ab >> bc >> cd;
  cout.precision(10);
  cout << (1 / bc * ab * cd);
  return 0;
}
