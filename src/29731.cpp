#include <iostream>
#include <string>

using namespace std;

string s[7] = {"Never gonna give you up",
               "Never gonna let you down",
               "Never gonna run around and desert you",
               "Never gonna make you cry",
               "Never gonna say goodbye",
               "Never gonna tell a lie and hurt you",
               "Never gonna stop"};

int main() {
  int n;
  string si;
  cin >> n;
  bool no = true;
  getline(cin, si);
  for (int i = 0; i < n; i++) {
    getline(cin, si);
    int c = 0;
    for (int j = 0; j < 7; j++)
      if (si == s[j])
        c++;
    if (c == 0)
      no = false;
  }
  cout << (no ? "No" : "Yes");
}