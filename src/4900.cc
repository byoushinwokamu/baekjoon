#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

#define ZERO 0b0111111  // 063
#define ONE 0b0001010   // 010
#define TWO 0b1011101   // 093
#define THREE 0b1001111 // 079
#define FOUR 0b1101010  // 106
#define FIVE 0b1100111  // 103
#define SIX 0b1110111   // 119
#define SEVEN 0b0001011 // 011
#define EIGHT 0b1111111 // 127
#define NINE 0b1101011  // 107
vector<int> num(0b10000000);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string input;
  int a, b, i;
  int t;
  cin >> input;
  num[ZERO] = 0;
  num[ONE] = 1;
  num[TWO] = 2;
  num[THREE] = 3;
  num[FOUR] = 4;
  num[FIVE] = 5;
  num[SIX] = 6;
  num[SEVEN] = 7;
  num[EIGHT] = 8;
  num[NINE] = 9;
  while (input != "BYE") {
    a = 0, b = 0;
    for (i = 0; input[i] != '+'; i += 3) {
      t = input[i] - '0';
      t *= 10;
      t += input[i + 1] - '0';
      t *= 10;
      t += input[i + 2] - '0';
      // cout << "A" << t << '\n';
      a *= 10;
      a += num[t];
    }
    for (i++; input[i] != '='; i += 3) {
      t = input[i] - '0';
      t *= 10;
      t += input[i + 1] - '0';
      t *= 10;
      t += input[i + 2] - '0';
      // cout << "B" << t << '\n';
      b *= 10;
      b += num[t];
    }
    a += b;
    char res[15];
    sprintf(res, "%d", a);
    cout << input;
    for (int i = 0; i < strlen(res); i++) {
      switch (res[i] - '0') {
      case 0:
        cout << "063";
        break;
      case 1:
        cout << "010";
        break;
      case 2:
        cout << "093";
        break;
      case 3:
        cout << "079";
        break;
      case 4:
        cout << "106";
        break;
      case 5:
        cout << "103";
        break;
      case 6:
        cout << "119";
        break;
      case 7:
        cout << "011";
        break;
      case 8:
        cout << "127";
        break;
      case 9:
        cout << "107";
        break;
      }
    }
    cout << '\n';
    cin >> input;
  }

  return 0;
}
