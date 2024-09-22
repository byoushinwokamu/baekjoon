#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pos;
vector<int> sor;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, p;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    pos.push_back(p);
    sor.push_back(p);
  }
  sort(sor.begin(), sor.end());
  sor.erase(unique(sor.begin(), sor.end()), sor.end());

  for (int i = 0; i < n; i++)
    cout << lower_bound(sor.begin(), sor.end(), pos[i]) - sor.begin() << ' ';

  return 0;
}