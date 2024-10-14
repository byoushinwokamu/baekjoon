#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  int b;
  cin >> b >> s;
  int n = 0;
  for (auto a : s) {
    switch (a) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      n++;
    }
  }
  cout << n;
}