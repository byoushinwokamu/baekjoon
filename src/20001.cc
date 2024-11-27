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
  string s;
  int mj = 0;
  while (s != "고무오리 디버깅 끝") {
    getline(cin, s);
    if (s == "문제")
      mj++;
    if (s == "고무오리")
      mj += (mj == 0 ? 2 : -1);
  }
  cout << (mj == 0 ? "고무오리야 사랑해" : "힝구");

  return 0;
}
