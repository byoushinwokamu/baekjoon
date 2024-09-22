#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  vector<int> v;
  int n;
  for (int i = 0; i < 10; i++) {
    cin >> n;
    v.push_back(n % 42);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v.end() - v.begin();

  return 0;
}