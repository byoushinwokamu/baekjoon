#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<unsigned int> aa, bb;
unsigned int maxx, beu;
int n, a, b, t;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> t;
    aa.push_back(t);
  }
  for (int i = 0; i < b; i++) {
    cin >> t;
    bb.push_back(t);
  }

  sort(aa.begin(), aa.end(), greater<unsigned int>());
  sort(bb.begin(), bb.end(), greater<unsigned int>());
  for (int i = 1; i < a; i++)
    aa[i] += aa[i - 1];
  for (int i = 1; i < b; i++)
    bb[i] += bb[i - 1];

  // now means length of 2*2 tiles
  // length of 2*1 tiles can be determined by n-now
  for (int now = n - n % 2; now >= 0; now -= 2) {
    if (n - now > a)
      break;
    if (now > b * 2)
      continue;
    beu = 0;
    if (now != 0)
      beu = bb[now / 2 - 1];
    if (now != n)
      beu += aa[n - now - 1];
    maxx = maxx > beu ? maxx : beu;
  }
  cout << maxx;

  return 0;
}