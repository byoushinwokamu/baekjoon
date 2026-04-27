// BOJ 4335
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  vector<bool> can(11, true);
  int n = 1;
  string s;

  cin >> n;
  cin.ignore();
  while (n != 0)
  {
    while (s != "right on")
    {
      getline(cin, s);
      if (s == "too high")
      {
        // cout << "TH" << endl;
        for (int i = n; i <= 10; i++) can[i] = false;
      }
      else if (s == "too low")
      {
        // cout << "TL" << endl;
        for (int i = n; i >= 1; i--) can[i] = false;
      }
      else if (s == "right on")
      {
        // cout << "RO" << endl;
        if (can[n]) cout << "Stan may be honest\n";
        else cout << "Stan is dishonest\n";
        break;
      }
      cin >> n;
      cin.ignore();
    }
    cin >> n;
    // cout << "N" << n << endl;
    cin.ignore();
    s = "";
    for (int i = 1; i <= 10; i++) can[i] = true;
  }

  return 0;
}
