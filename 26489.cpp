#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  string str;
  int i = 0;
  while (!cin.eof()) {
    getline(cin, str);
    i++;
  }
  cout << i;

  return 0;
}