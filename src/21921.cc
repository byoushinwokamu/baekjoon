#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int s = 0;
  for (int i = 0; i < x; i++)
    s += v[i];
  int m = s;
  int c = 1;
  for (int i = x; i < n; i++) {
    s -= v[i - x];
    s += v[i];
    if (m == s)
      c++;
    else if (m < s)
      m = s, c = 1;
  }
  if (m == 0)
    cout << "SAD";
  else
    cout << m << '\n' << c;

  return 0;
}