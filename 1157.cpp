#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  string str;
  cin >> str;
  vector<int> count(26, 0);
  for (int i = 0; i < str.length(); i++) {
    if (str[i] > 96)
      count[str[i] - 97]++;
    else
      count[str[i] - 65]++;
  }
  int max = 0;
  int maxi = -1;
  bool q = false;
  for (int i = 0; i < 26; i++) {
    if (max < count[i]) {
      q = false;
      max = count[i];
      maxi = i;
    } else if (max == count[i])
      q = true;
  }
  if (q)
    cout << "?";
  else
    cout << static_cast<char>(maxi + 65);

  return 0;
}