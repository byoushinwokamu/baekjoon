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
  vector<int> res(n);
  int t1 = -1, t2 = -1;
  for (int i = 0; i < n; i++) {
    cout << "? " << name[i] << endl;
    cin >> res[i];
    if (res[i] == 1)
      if (t1 == -1)
        t1 = i;
      else {
        t2 = i;
        break;
      }
  }
  if (t1 == t2) {
    for (int i = 0; i < n; i++) {
      cout << "? " << name[i] << endl;
      cin >> res[i];
      if (res[i]) {
        cout << "! " << name[i] << endl;
        return 0;
      }
    }
  } else if (t2 != -1) {
    cout << "? " << name[t1] << endl;
    cin >> res[0];
    cout << "! " << (res[0] ? name[t1] : name[t2]) << endl;
  } else {
    cout << "! " << name[t1] << endl;
  }

  return 0;
}