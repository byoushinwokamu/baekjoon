#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
bool alp[26];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n;
  string s;
  char s2[100];
  cin >> n >> s;
  int beflen = s.length();
  for (auto i = s.begin(); i != s.end(); i++) {
    if (alp[*i - 'a'])
      i = s.erase(i) - 1;
    else
      alp[*i - 'a'] = true;
  }

  cout << "smupc_";

  int tail = beflen - s.length() + 4;
  if (tail >= 10)
    cout << tail % 10 << tail / 10;
  else
    cout << tail;

  for (auto i = s.rbegin(); i != s.rend(); i++)
    cout << *i;

  sprintf(s2, "%d", n + 1906);
  cout << s2[3] << s2[2] << s2[1] << s2[0];

  return 0;
}