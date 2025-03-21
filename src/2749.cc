// BOJ 2749
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int mat[3][2][2];

void matmul(ll a, ll b, ll r) {
  mat[r][0][0] =
      (mat[a][0][0] * mat[b][0][0] + mat[a][0][1] * mat[b][1][0]) % 1'000'000;
  mat[r][0][1] =
      (mat[a][0][0] * mat[b][0][1] + mat[a][0][1] * mat[b][1][1]) % 1'000'000;
  mat[r][1][0] =
      (mat[a][1][0] * mat[b][0][0] + mat[a][1][1] * mat[b][1][0]) % 1'000'000;
  mat[r][1][1] =
      (mat[a][1][0] * mat[b][0][1] + mat[a][1][1] * mat[b][1][1]) % 1'000'000;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  ll i = 1;
  mat[0][0][0] = 0;
  mat[0][0][1] = 1;
  mat[0][1][0] = 1;
  mat[0][1][1] = 1;
  int a = 0, b = 1, t = -1;
  while (i * 2 < n) {
    matmul(a, a, b);
    t = a, a = b, b = t;
    i <<= 1;
  }

  return 0;
}
