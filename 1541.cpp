#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, char> P; // char: i/c
vector<P> v;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  string str;
  cin >> str;
  string temp = "";
  for (char c : str) {
    if (c == '+' || c == '-') {
      v.push_back(make_pair(stoi(temp), 'i'));
      v.push_back(make_pair(c == '+' ? 1 : 0, 'c'));
      temp = "";
    } else {
      temp.append(1, c);
    }
  }
  if (temp.length() != 0)
    v.push_back(make_pair(stoi(temp), 'i'));
  int res = 0;
  bool neg = false;
  for (auto i : v) {
    if (i.second == 'i')
      res += neg ? (-i.first) : (i.first);
    else if (i.first == 0)
      neg = true;
  }
  cout << res;

  return 0;
}