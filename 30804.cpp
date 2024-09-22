#include <iostream>
#include <vector>

using namespace std;
int n, maxn, chpos, fr, fn, ff;
vector<int> v(200000);

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  if (n == 1) {
    cout << 1;
    return 0;
  }

  fr |= (1 << v[0]), fn = 1, ff = 1;
  for (int i = 1; i < n; i++) {
    if (fr & (1 << v[i])) {
      fn++;
      if (v[i] != v[chpos])
        chpos = i;
    } else if (ff == 1)
      fr |= (1 << v[i]), fn++, chpos = i, ff++;
    else
      fr = (1 << v[chpos]) | (1 << v[i]), fn = i - chpos + 1, chpos = i;
    maxn = maxn > fn ? maxn : fn;
  }
  cout << maxn;

  return 0;
}