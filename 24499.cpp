#include <iostream>
#include <vector>

using namespace std;
int n, k, t;
vector<int> v(222222);
vector<int> vsum(111111);

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> v[i], v[i + n] = v[i];
  for (int i = 0; i < k; i++)
    vsum[0] += v[i];
  for (int i = 1; i < n; i++) {
    vsum[i] = vsum[i - 1] + v[i + k - 1] - v[i - 1];
  }
  int maxx = 0;
  for (int i = 0; i < n; i++)
    maxx = maxx > vsum[i] ? maxx : vsum[i];
  cout << maxx;

  return 0;
}