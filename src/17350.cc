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
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    if (s == "anj") {
      cout << "뭐야;";
      return 0;
    }
  }
  cout << "뭐야?";

  return 0;
}
