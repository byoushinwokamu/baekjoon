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
  cin >> n;
  for (int i = 0; i < 2 * n - 1; i++) {
    if (i == 0 || i == 2 * n - 2) {
      int a = n;
      while (a--)
        cout << '*';
      a = 2 * n - 3;
      while (a--)
        cout << ' ';
      a = n;
      while (a--)
        cout << '*';
      cout << '\n';
    } else if (i == n - 1) {
      int a = n - 1;
      while (a--)
        cout << ' ';
      cout << '*';
      a = n - 2;
      while (a--)
        cout << ' ';
      cout << '*';
      a = n - 2;
      while (a--)
        cout << ' ';
      cout << "*\n";
    } else {
      int z = (i < n ? i : 2 * n - i - 2);
      int a = z;
      while (a--)
        cout << ' ';
      cout << '*';
      a = n - 2;
      while (a--)
        cout << ' ';
      cout << '*';
      a = 2 * (n - z) - 3;
      while (a--)
        cout << ' ';
      cout << '*';
      a = n - 2;
      while (a--)
        cout << ' ';
      cout << "*\n";
    }
  }

  return 0;
}
