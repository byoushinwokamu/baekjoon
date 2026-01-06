// BOJ 1543
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s, w;
  getline(cin, s);
  getline(cin, w);
  size_t i = 0, c = 0;
  while (i < s.length())
  {
    size_t pos = s.find(w, i);
    if (pos != string::npos)
      i = pos + w.length(), c++;
    else
      break;
  }
  cout << c;

  return 0;
}
