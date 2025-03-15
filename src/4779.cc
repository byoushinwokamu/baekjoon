// BOJ 4779
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

const int p[] = {1,    3,    9,     27,    81,     243,   729,
                 2187, 6561, 19683, 59049, 177147, 531441};

void print(int level) {
  if (level == 0) {
    cout << '-';
    return;
  }
  print(level - 1);
  for (int i = 0; i < p[level - 1]; i++)
    cout << ' ';
  print(level - 1);
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  while (!cin.eof()) {
    print(n);
    cout << '\n';
    cin >> n;
  }

  return 0;
}
