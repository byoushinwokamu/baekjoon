#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int n, m, h;
vector<int> v;
int c;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  h = ceil((double)m * 9 / 10);
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }

  return 0;
}