#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<int> pt; // num to point
vector<int> rn; // room to num
vector<int> nr; // num to room
int n, h = 0, j, b, m, san, bul;
int combo = 0, maxcombo = 0, cnt = 0;

void swaproom(int gr, int br) { // good room, bad room
  int p1 = rn[gr], p2 = rn[br];
  rn[br] = p1, rn[gr] = p2;
  nr[p1] = br, nr[p2] = gr;
  pt[p1] += 2, pt[p2] -= 2;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> j >> b >> m;
  pt.resize(n), rn.resize(n), nr.resize(n);
  j--;

  // room number initialize
  for (int i = 0; i < n; i++)
    rn[i] = i, nr[i] = i;

  // for each week
  for (int w = 0; w < m - 1; w++) {
    // check kibun
    if (abs(nr[h] - nr[j]) <= b)
      cnt++, maxcombo = max(++combo, maxcombo);
    else
      combo = 0;

    // input sanbuljeom
    fill(pt.begin(), pt.end(), 0);
    for (int i = 0; i < n; i++)
      cin >> san, pt[i] += san;
    for (int i = 0; i < n; i++)
      cin >> bul, pt[i] -= bul;

    // check room change
    for (int i = 0; i < n - 1; i++) {
      if (pt[rn[i]] >= 0 && pt[rn[i + 1]] >= 0) {
        if (pt[rn[i]] + 2 <= pt[rn[i + 1]])
          swaproom(i, i + 1);
      } else if (pt[rn[i]] >= 0 && pt[rn[i + 1]] < 0) {
      } else if (pt[rn[i]] < 0 && pt[rn[i + 1]] >= 0) {
        swaproom(i, i + 1);
      } else if (pt[rn[i]] < 0 && pt[rn[i + 1]] < 0) {
        if (pt[rn[i]] + 4 <= pt[rn[i + 1]])
          swaproom(i, i + 1);
      }
    }
  }
  if (abs(nr[h] - nr[j]) <= b)
    cnt++, maxcombo = max(++combo, maxcombo);
  cout << cnt << ' ' << maxcombo;

  return 0;
}
