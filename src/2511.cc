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
  vector<int> a(10), b(10);
  int aa = 0, bb = 0;
  char last = 0;
  for (int i = 0; i < 10; i++)
    cin >> a[i];
  for (int i = 0; i < 10; i++)
    cin >> b[i];
  for (int i = 0; i < 10; i++)
    if (a[i] > b[i])
      aa += 3, last = 'a';
    else if (a[i] < b[i])
      bb += 3, last = 'b';
    else
      aa++, bb++;
  cout << aa << ' ' << bb << '\n';
  cout << (aa > bb
               ? 'A'
               : (aa < bb ? 'B'
                          : (last == 'a' ? 'A' : (last == 'b' ? 'B' : 'D'))));
  return 0;
}