#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<vector<pp>> adj(100001);
vector<int> linked(100001);
int v, n, d;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> v;
  for (int i = 0; i < v; i++) {
    cin >> n;
    if (n == -1)
      continue;
    cin >> d;
  }

  return 0;
}
