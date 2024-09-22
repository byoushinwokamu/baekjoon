#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  if (s == "1")
    cout << 2;
  else
    cout << 1;

  return 0;
}