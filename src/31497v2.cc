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
  cin >> n;
  vector<string> name(n);
  for (int i = 0; i < n; i++)
    cin >> name[i];
  bool lied = false;
  int res = 0, ress = 0;
  for (int i = 0; i < n; i++) {
    cout << "? " << name[i] << endl;
    cin >> res;
    if (!lied) {
      cout << "? " << name[i] << endl;
      cin >> ress;
      if (ress != res) {
        lied = true, i--;
        continue;
      } else if (res == 1) {
        cout << "! " << name[i] << endl;
        return 0;
      }
    } else if (res == 1) {
      cout << "! " << name[i] << endl;
      return 0;
    }
  }

  return 0;
}