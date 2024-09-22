#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
char input[3];
int t, n;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    cin >> n;
    vector<char> v1, v2;
    for (int i = 0; i < n; i++) {
      cin >> input;
      v1.push_back(((int)input[0] - 'B') * 2 + (int)input[1] - '0');
    }
    for (int i = 0; i < n; i++) {
      cin >> input;
      v2.push_back(((int)input[0] - 'B') * 2 + (int)input[1] - '0');
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    bool same = true;
    for (int i = 0; i < n; i++)
      if (v1[i] != v2[i]) {
        same = false;
        break;
      }
    cout << (same ? "NOT " : "") << "CHEATER\n";
  }

  return 0;
}