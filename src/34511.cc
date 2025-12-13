// BOJ 34511
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
  int n, m, c = 0;
  vector<string> puzzle;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    puzzle.push_back(""), cin >> puzzle[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (puzzle[i][j] != 'X') continue;
      if (i > 0 && puzzle[i - 1][j] == 'Y') c++;
      if (j > 0 && puzzle[i][j - 1] == 'Y') c++;
      if (i < n - 1 && puzzle[i + 1][j] == 'Y') c++;
      if (j < m - 1 && puzzle[i][j + 1] == 'Y') c++;
    }

  cout << c;

  return 0;
}
