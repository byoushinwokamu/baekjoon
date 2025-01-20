#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, a, ab = 0;
  cin >> n;
  enum { ASCE, DESC, SAME } stat = SAME;
  int len = 1, mlen = 1;
  cin >> ab;
  for (int i = 1; i < n; i++) {
    cin >> a;
    if (stat == ASCE)
      if (ab < a)
        mlen = max(++len, mlen);
      else if (ab == a)
        stat = SAME, len = 1;
      else
        stat = DESC, mlen = max(++len, mlen);
    else if (stat == DESC)
      if (ab > a)
        mlen = max(++len, mlen);
      else if (ab == a)
        stat = SAME, len = 1;
      else
        stat = ASCE, len = 2;
    else // stat == SAME
      if (ab > a)
        stat = DESC, mlen = max(++len, mlen);
      else if (ab == a)
        ;
      else
        stat = ASCE, mlen = max(++len, mlen);
    ab = a;
  }
  cout << mlen;

  return 0;
}
