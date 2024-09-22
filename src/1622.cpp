#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  string a, b;
  while (getline(cin, a), getline(cin, b)) {
    int aa[26] = {
        0,
    };
    int bb[26] = {
        0,
    };
    for (auto c : a)
      aa[c - 97]++;
    for (auto c : b)
      bb[c - 97]++;
    for (int i = 0; i < 26; i++)
      for (int j = min(aa[i], bb[i]); j > 0; j--)
        cout << (char)(i + 97);

    cout << '\n';
  }

  return 0;
}