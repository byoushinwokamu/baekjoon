#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n;
int s, e;
int slast = 0, efirst = 100001;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> e;
    slast = max(slast, s);
    efirst = min(efirst, e);
  }
  cout << (slast >= efirst ? slast - efirst : 0);

  return 0;
}
