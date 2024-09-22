#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int a, b, v;
  cin >> a >> b >> v;
  if (a == v)
    cout << 1;
  else if ((v - b) % (a - b) == 0)
    cout << (v - b) / (a - b);
  else
    cout << (v - b) / (a - b) + 1;

  return 0;
}