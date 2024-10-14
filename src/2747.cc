#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<ll> fibo(46);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  fibo[1] = 1;
  for (int i = 2; i <= 45; i++)
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  int n;
  cin >> n;
  cout << fibo[n];

  return 0;
}
