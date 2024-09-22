#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, v;
long long summ, vsize = 1;
string str[5];
int num[10] = {0b111101101101111, 0b100100100100100, 0b111001111100111,
               0b111100111100111, 0b100100111101101, 0b111100111001111,
               0b111101111001111, 0b100100100100111, 0b111101111101111,
               0b111100111101111};
vector<vector<int>> vv;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 5; i++)
    cin >> str[i];

  for (int i = 0; i < n; i++) { // for each character
    vv.push_back(vector<int>(0));
    v = 0;
    for (int j = 0; j < 3; j++) {   // for each column
      for (int k = 0; k < 5; k++) { // for each row
        v |= (str[k][4 * i + j] == '#' ? 1 : 0) << (k * 3 + j);
      }
    }
    for (int j = 0; j <= 9; j++) {
      if ((num[j] | v) == num[j])
        vv[i].push_back(j);
    }
  }
  for (auto i : vv) {
    if (i.empty()) {
      cout << -1;
      return 0;
    }
    vsize *= i.size();
  }
  for (int i = 0; i < n; i++) {
    for (auto j : vv[i]) {
      summ += vsize / vv[i].size() * j;
    }
    summ *= 10;
  }
  cout << (double)summ / 10 / vsize;

  return 0;
}