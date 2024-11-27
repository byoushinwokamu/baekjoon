#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<int> prime;
vector<bool> isnp(5000001);

// 에라토스테네스의 체를 사용할 필요가 없었다...

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  for (int i = 2; i <= 5000000; i++) {
    if (isnp[i])
      continue;
    prime.push_back(i);
    for (int j = 2; i * j <= 5000000; j++)
      isnp[i * j] = true;
  }
  int n;
  cin >> n;
  for (auto p : prime) {
    while (n % p == 0)
      cout << p << '\n', n /= p;
  }

  return 0;
}
