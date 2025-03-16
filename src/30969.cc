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
  ll fee;
  string s;
  vector<int> road(1002);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> fee;
    if (fee > 1000)
      road[1001]++;
    else
      road[fee]++;
    if (s == "jinju")
      jinju = fee;
  }
  int sum = 0;
  for (int i = jinju + 1; i <= 1001; i++)
    sum += road[i];
  cout << jinju << '\n' << sum;

  return 0;
}
