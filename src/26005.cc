// BOJ 26005
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
  int n;
  cin >> n;
  switch (n)
  {
  case 1:
    cout << 0;
    break;
  case 2:
    cout << 2;
    break;
  default:
    if (n % 2) cout << (n * n / 2) + 1;
    else cout << (n * n / 2);
  }

  return 0;
}
