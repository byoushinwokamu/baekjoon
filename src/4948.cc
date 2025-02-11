// BOJ 4948
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> isnoprime(333333);
vector<int> prime;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  isnoprime[1] = true;
  for (int i = 2; i <= 246912; i++) {
    if (isnoprime[i])
      continue;
    prime.push_back(i);
    for (int j = 2; i * j <= 246912; j++) {
      isnoprime[i * j] = true;
    }
  }
  cin >> n;
  while (n) {
    int c = 0;
    for (auto i : prime) {
      if (i > 2 * n)
        break;
      if (i > n)
        c++;
    }
    cout << c << '\n';
    cin >> n;
  }

  return 0;
}
