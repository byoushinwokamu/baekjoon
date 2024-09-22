#include <iostream>

using namespace std;

int pow2(int n) {
  int res = 1;
  for (int i = 0; i < n; i++)
    res *= 2;
  return res;
}

void hanoi(int from, int mid, int dest, int h) {
  if (h == 1) {
    cout << from << " " << dest << "\n";
  } else {
    hanoi(from, dest, mid, h - 1);
    cout << from << " " << dest << "\n";
    hanoi(mid, from, dest, h - 1);
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int pow = pow2(n);
  cout << pow - 1 << '\n';

  hanoi(1, 2, 3, n);

  return 0;
}