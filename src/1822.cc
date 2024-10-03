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
  int na, nb;
  cin >> na >> nb;
  vector<int> a(na), b(nb);
  for (int i = 0; i < na; i++)
    cin >> a[i];
  for (int i = 0; i < nb; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int cnt = 0;
  vector<int> ex;
  int ca = 0, cb = 0;
  while (cb < nb) {
    if (a[ca] == b[cb]) {
      ca++;
    } else if (a[ca] > b[cb]) {
      cb++;
    } else {
      cnt++, ex.push_back(a[ca++]);
    }
    if (ca == na)
      break;
  }
  while (ca < na) {
    cnt++, ex.push_back(a[ca++]);
  }
  cout << cnt << '\n';
  for (auto k : ex)
    cout << k << ' ';

  return 0;
}