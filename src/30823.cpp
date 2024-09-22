#include <iostream>

using namespace std;

int n, k;
char s[1000010];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> k >> s;
  if ((n + k) % 2) {
    for (int i = 0; i < k - 1; i++) {
      s[n++] = s[i];
    }
  } else {
    for (int i = 0; i < k - 1; i++) {
      s[n++] = s[k - 2 - i];
    }
  }
  cout << s + k - 1;

  return 0;
}