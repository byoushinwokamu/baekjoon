// BOJ 14381
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
  int t, n;
  cin >> t;
  for (int tt = 1; tt <= t; tt++)
  {
    cin >> n;
    if (!n)
    {
      cout << "Case #" << tt << ": INSOMNIA\n";
      continue;
    }

    int in = n, i = 1, nokori = 10;
    vector<bool> checked(10);
    while (nokori)
    {
      string s = to_string(in);
      for (auto c : s)
        if (!checked[c - '0']) checked[c - '0'] = true, nokori--;
      in += n, i++;
    }
    cout << "Case #" << tt << ": " << in - n << '\n';
  }

  return 0;
}
