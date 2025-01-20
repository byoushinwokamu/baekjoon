#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> isnotprime;
vector<int> prime;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  // 이면수: 5를 제외하고 4 이상이면서 자리수의 합이 홀수
  // 임현수: 2,4,또는 소인수분해했을 때 소인수 종류가 짝수개
  // 둘다 아니면 성경수
  // 이면수 1 임현수 2 둘다아니면 3 둘다면 4
  int n, nn;
  cin >> n;
  nn = n;
  for (int i = 2; 2 * i <= n; i++) {
    if (isnotprime[i])
      continue;
    prime.push_back(i);
    for (int j = 2; i * j <= n; j++)
      isnotprime[i * j] = true;
  }
  bool ims = false, ihs = false;
  if (n > 3 && n != 5) {
    int s = 0;
    while (n)
      s += n % 10, n /= 10;
    if (s % 2)
      ims = true;
  }
  n = nn;
  if (n == 2 || n == 4)
    ihs = true;
  else {
    vector<int> sis;
    while (n > 1) {
      for (auto i : prime) {
        if (n % i)
          ;
      }
    }
  }

  return 0;
}
