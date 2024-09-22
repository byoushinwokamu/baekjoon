#include <iostream>
#include <string>

using namespace std;

bool ismoeum(char ch) {
  switch (ch) {
  case 'a':
  case 'A':
  case 'e':
  case 'E':
  case 'i':
  case 'I':
  case 'o':
  case 'O':
  case 'u':
  case 'U':
    return true;
  }
  return false;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  string str;
  getline(cin, str);
  while (str != "#") {
    int c = 0;
    for (char ch : str)
      if (ismoeum(ch))
        c++;
    cout << c << '\n';
    getline(cin, str);
  }

  return 0;
}