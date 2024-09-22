#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int min = 1000001;
  int max = -1000001;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    min = min < a ? min : a;
    max = max > a ? max : a;
  }
  cout << min << " " << max;

  return 0;
}