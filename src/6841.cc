// BOJ 6841
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s;
  do {
    cin >> s;
    if (s == "CU")
      cout << "see you\n";
    else if (s == ":-)")
      cout << "I’m happy\n";
    else if (s == ":-(")
      cout << "I’m unhappy\n";
    else if (s == ";-)")
      cout << "wink\n";
    else if (s == ":-P")
      cout << "stick out my tongue\n";
    else if (s == "(~.~)")
      cout << "sleepy\n";
    else if (s == "TA")
      cout << "totally awesome\n";
    else if (s == "CCC")
      cout << "Canadian Computing Competition\n";
    else if (s == "CUZ")
      cout << "because\n";
    else if (s == "TY")
      cout << "thank-you\n";
    else if (s == "YW")
      cout << "you’re welcome\n";
    else if (s == "TTYL")
      cout << "talk to you later\n";
    else
      cout << s << '\n';

  } while (s != "TTYL");

  return 0;
}
