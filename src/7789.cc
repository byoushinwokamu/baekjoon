// BOJ 7789
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> isnotprime(10000000);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  for (int i = 2; i < 10000000; i++) {
    if (isnotprime[i])
      continue;
    for (int j = 2; i * j < 10000000; j++)
      isnotprime[i * j] = true;
  }
  int a, b;
  cin >> a >> b;
  if (!isnotprime[a])
    if (!isnotprime[a + b * 1000000]) {
      cout << "Yes";
      return 0;
    }
  cout << "No";

  return 0;
}
