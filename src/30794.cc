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
  int lv;
  string jd;
  cin >> lv >> jd;
  if (jd == "miss")
    lv *= 0;
  else if (jd == "bad")
    lv *= 200;
  else if (jd == "cool")
    lv *= 400;
  else if (jd == "great")
    lv *= 600;
  else if (jd == "perfect")
    lv *= 1000;
  cout << lv;

  return 0;
}
