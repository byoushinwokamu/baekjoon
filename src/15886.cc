#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  int c = 1;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'W' && s[i] == 'E')
      c++;
  }
  cout << c;

  return 0;
}