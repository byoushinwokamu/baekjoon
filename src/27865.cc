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
  int n;
  cin >> n;
  char c;
  for (;;) {
    cout << "? 1" << endl;
    cin >> c;
    if (c == 'Y')
      cout << "! 1" << flush;
  }

  return 0;
}
