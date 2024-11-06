#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<char, int> pp;

vector<vector<int>> adj(26);

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  {
    adj['Q' - 'A'].push_back('W' - 'A');
    adj['Q' - 'A'].push_back('A' - 'A');

    adj['W' - 'A'].push_back('Q' - 'A');
    adj['W' - 'A'].push_back('A' - 'A');
    adj['W' - 'A'].push_back('S' - 'A');
    adj['W' - 'A'].push_back('E' - 'A');

    adj['E' - 'A'].push_back('W' - 'A');
    adj['E' - 'A'].push_back('S' - 'A');
    adj['E' - 'A'].push_back('D' - 'A');
    adj['E' - 'A'].push_back('R' - 'A');

    adj['R' - 'A'].push_back('E' - 'A');
    adj['R' - 'A'].push_back('D' - 'A');
    adj['R' - 'A'].push_back('F' - 'A');
    adj['R' - 'A'].push_back('T' - 'A');

    adj['T' - 'A'].push_back('R' - 'A');
    adj['T' - 'A'].push_back('F' - 'A');
    adj['T' - 'A'].push_back('G' - 'A');
    adj['T' - 'A'].push_back('Y' - 'A');

    adj['Y' - 'A'].push_back('T' - 'A');
    adj['Y' - 'A'].push_back('G' - 'A');
    adj['Y' - 'A'].push_back('H' - 'A');
    adj['Y' - 'A'].push_back('U' - 'A');

    adj['U' - 'A'].push_back('Y' - 'A');
    adj['U' - 'A'].push_back('H' - 'A');
    adj['U' - 'A'].push_back('J' - 'A');
    adj['U' - 'A'].push_back('I' - 'A');

    adj['I' - 'A'].push_back('U' - 'A');
    adj['I' - 'A'].push_back('J' - 'A');
    adj['I' - 'A'].push_back('K' - 'A');
    adj['I' - 'A'].push_back('O' - 'A');

    adj['O' - 'A'].push_back('I' - 'A');
    adj['O' - 'A'].push_back('K' - 'A');
    adj['O' - 'A'].push_back('L' - 'A');
    adj['O' - 'A'].push_back('P' - 'A');

    adj['P' - 'A'].push_back('O' - 'A');
    adj['P' - 'A'].push_back('L' - 'A');

    adj['A' - 'A'].push_back('Q' - 'A');
    adj['A' - 'A'].push_back('W' - 'A');
    adj['A' - 'A'].push_back('S' - 'A');
    adj['A' - 'A'].push_back('Z' - 'A');

    adj['S' - 'A'].push_back('W' - 'A');
    adj['S' - 'A'].push_back('E' - 'A');
    adj['S' - 'A'].push_back('A' - 'A');
    adj['S' - 'A'].push_back('D' - 'A');
    adj['S' - 'A'].push_back('Z' - 'A');
    adj['S' - 'A'].push_back('X' - 'A');

    adj['D' - 'A'].push_back('E' - 'A');
    adj['D' - 'A'].push_back('R' - 'A');
    adj['D' - 'A'].push_back('S' - 'A');
    adj['D' - 'A'].push_back('F' - 'A');
    adj['D' - 'A'].push_back('X' - 'A');
    adj['D' - 'A'].push_back('C' - 'A');

    adj['F' - 'A'].push_back('R' - 'A');
    adj['F' - 'A'].push_back('T' - 'A');
    adj['F' - 'A'].push_back('D' - 'A');
    adj['F' - 'A'].push_back('G' - 'A');
    adj['F' - 'A'].push_back('C' - 'A');
    adj['F' - 'A'].push_back('V' - 'A');

    adj['G' - 'A'].push_back('T' - 'A');
    adj['G' - 'A'].push_back('Y' - 'A');
    adj['G' - 'A'].push_back('F' - 'A');
    adj['G' - 'A'].push_back('H' - 'A');
    adj['G' - 'A'].push_back('V' - 'A');
    adj['G' - 'A'].push_back('B' - 'A');

    adj['H' - 'A'].push_back('Y' - 'A');
    adj['H' - 'A'].push_back('U' - 'A');
    adj['H' - 'A'].push_back('G' - 'A');
    adj['H' - 'A'].push_back('J' - 'A');
    adj['H' - 'A'].push_back('B' - 'A');
    adj['H' - 'A'].push_back('N' - 'A');

    adj['J' - 'A'].push_back('U' - 'A');
    adj['J' - 'A'].push_back('I' - 'A');
    adj['J' - 'A'].push_back('H' - 'A');
    adj['J' - 'A'].push_back('K' - 'A');
    adj['J' - 'A'].push_back('N' - 'A');
    adj['J' - 'A'].push_back('M' - 'A');

    adj['K' - 'A'].push_back('I' - 'A');
    adj['K' - 'A'].push_back('O' - 'A');
    adj['K' - 'A'].push_back('J' - 'A');
    adj['K' - 'A'].push_back('L' - 'A');
    adj['K' - 'A'].push_back('M' - 'A');

    adj['L' - 'A'].push_back('O' - 'A');
    adj['L' - 'A'].push_back('P' - 'A');
    adj['L' - 'A'].push_back('K' - 'A');

    adj['Z' - 'A'].push_back('A' - 'A');
    adj['Z' - 'A'].push_back('S' - 'A');
    adj['Z' - 'A'].push_back('X' - 'A');

    adj['X' - 'A'].push_back('S' - 'A');
    adj['X' - 'A'].push_back('D' - 'A');
    adj['X' - 'A'].push_back('Z' - 'A');
    adj['X' - 'A'].push_back('C' - 'A');

    adj['C' - 'A'].push_back('X' - 'A');
    adj['C' - 'A'].push_back('D' - 'A');
    adj['C' - 'A'].push_back('F' - 'A');
    adj['C' - 'A'].push_back('V' - 'A');

    adj['V' - 'A'].push_back('C' - 'A');
    adj['V' - 'A'].push_back('F' - 'A');
    adj['V' - 'A'].push_back('G' - 'A');
    adj['V' - 'A'].push_back('B' - 'A');

    adj['B' - 'A'].push_back('V' - 'A');
    adj['B' - 'A'].push_back('G' - 'A');
    adj['B' - 'A'].push_back('H' - 'A');
    adj['B' - 'A'].push_back('N' - 'A');

    adj['N' - 'A'].push_back('B' - 'A');
    adj['N' - 'A'].push_back('H' - 'A');
    adj['N' - 'A'].push_back('J' - 'A');
    adj['N' - 'A'].push_back('M' - 'A');

    adj['M' - 'A'].push_back('N' - 'A');
    adj['M' - 'A'].push_back('J' - 'A');
    adj['M' - 'A'].push_back('K' - 'A');
  }

  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    int tim = s.length();
    for (int i = 0; i < s.length() - 1; i++) {
      queue<pp> q;
      vector<bool> vis(26);
      q.push({s[i], 0});
      vis[s[i] - 'A'] = true;
      char d = s[i + 1];

      char c;
      int n;
      while (!q.empty()) {
        c = q.front().fi;
        n = q.front().se;
        if (c == d) {
          break;
        }
        for (auto a : adj[c - 'A']) {
          if (vis[a])
            continue;
          q.push({a + 'A', n + 1});
          vis[a] = true;
        }
        q.pop();
      }
      tim += n * 2;
    }
    cout << tim << '\n';
  }

  return 0;
}
