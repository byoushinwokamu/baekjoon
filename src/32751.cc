// BOJ 32751
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
  int n;
  int jr[4];
  cin >> n >> jr[0] >> jr[1] >> jr[2] >> jr[3];
  string s;
  cin >> s;
  bool oishi = true;

  if (*s.begin() != 'a')
    oishi = false;
  if (*s.rbegin() != 'a')
    oishi = false;

  for (int i = 1; i < n - 1 && oishi; i++) {
    if (s[i] == s[i - 1])
      oishi = false;
    jr[s[i] - 'a']--;
  }
  if (*s.rbegin() == *(s.rbegin() + 1))
    oishi = false;
  jr[0] -= s.length() > 1 ? 2 : 1;
  for (int i = 0; i < 4; i++)
    if (jr[i] < 0)
      oishi = false;

  cout << (oishi ? "Yes" : "No");

  return 0;
}
