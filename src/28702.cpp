#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  int res;
  for (int i = 0; i < 3; i++) {
    if (s[i] == "Fizz")
      continue;
    else if (s[i] == "Buzz")
      continue;
    else if (s[i] == "FizzBuzz")
      continue;
    else {
      res = stoi(s[i]) + 3 - i;
      break;
    }
  }
  if (res % 3 == 0)
    if (res % 5 == 0)
      cout << "FizzBuzz";
    else
      cout << "Fizz";
  else if (res % 5 == 0)
    cout << "Buzz";
  else
    cout << res;

  return 0;
}