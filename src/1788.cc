#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<ll> fibo(2000002);
vector<bool> sg(2000002);
const int zero = 1000001;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  fibo[zero] = 0, fibo[zero + 1] = 1, sg[zero + 1] = true;
  for (int i = 2; i <= 1000000; i++) {
    fibo[zero + i] = (fibo[zero + i - 1] + fibo[zero + i - 2]) % 1000000000;
    sg[zero + i] = true;
  }
  for (int i = -1; i >= -1000000; i--) {
    fibo[zero + i] = (fibo[zero + i + 2] - fibo[zero + i + 1]) % 1000000000;
    sg[zero + i] = ((-i) % 2 == 0 ? false : true);
  }

  int n;
  cin >> n;
  if (n == 0)
    cout << "0\n0";
  else
    cout << (sg[zero + n] ? 1 : -1) << '\n' << abs(fibo[n + zero]);

  return 0;
}
