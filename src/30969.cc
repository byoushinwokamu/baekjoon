// BOJ 30969
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
  int n, jinju;
  cin >> n;
  vector<int> fee(n);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s >> fee[i];
    if (s == "jinju")
      jinju = fee[i];
  }
  sort(fee.begin(), fee.end());
  auto it = find(fee.begin(), fee.end(), jinju);
  cout << jinju << '\n' << (int)(fee.end() - it - 1);

  return 0;
}
