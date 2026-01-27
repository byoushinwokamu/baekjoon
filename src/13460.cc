// BOJ 13460
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m;

enum
{
  up,
  down,
  left,
  right
} dir;

constexpr int dx[4] = {0, 0, -1, 1};
constexpr int dy[4] = {-1, 1, 0, 0};

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; i++) cin >> board[i];

  return 0;
}
