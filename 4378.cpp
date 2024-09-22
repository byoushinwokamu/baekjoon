#include <iostream>
#include <string>

using namespace std;
char tr[128];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  tr['W'] = 'Q';
  tr['E'] = 'W';
  tr['R'] = 'E';
  tr['T'] = 'R';
  tr['Y'] = 'T';
  tr['U'] = 'Y';
  tr['I'] = 'U';
  tr['O'] = 'I';
  tr['P'] = 'O';
  tr['['] = 'P';
  tr[']'] = '[';
  tr['\\'] = ']';
  tr['S'] = 'A';
  tr['D'] = 'S';
  tr['F'] = 'D';
  tr['G'] = 'F';
  tr['H'] = 'G';
  tr['J'] = 'H';
  tr['K'] = 'J';
  tr['L'] = 'K';
  tr[';'] = 'L';
  tr['\''] = ';';
  tr['X'] = 'Z';
  tr['C'] = 'X';
  tr['V'] = 'C';
  tr['B'] = 'V';
  tr['N'] = 'B';
  tr['M'] = 'N';
  tr[','] = 'M';
  tr['.'] = ',';
  tr['/'] = '.';
  tr['1'] = '`';
  tr['2'] = '1';
  tr['3'] = '2';
  tr['4'] = '3';
  tr['5'] = '4';
  tr['6'] = '5';
  tr['7'] = '6';
  tr['8'] = '7';
  tr['9'] = '8';
  tr['0'] = '9';
  tr['-'] = '0';
  tr['='] = '-';
  tr[' '] = ' ';
  string s;
  while (true) {
    getline(cin, s);
    for (char c : s)
      cout << tr[c];
    if (cin.eof())
      break;
    cout << '\n';
  }

  return 0;
}