// BOJ 1652
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

// #define DIM 2
// #define MAXROOMSIZE 10000

// int du[DIM];

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;

  // du[0] = 1;
  // for (int i = 1; i < DIM; i++)
  //   du[i] = du[i - 1] * n;

  vector<string> room(n);
  for (int i = 0; i < n; i++)
    cin >> room[i];

  int cnt = 0;
  for (int r = 0; r < n; r++)
  {
    int combo = 0;
    for (int c = 0; c < n; c++)
      if (room[r][c] == '.')
      {
        if (++combo == 2)
          cnt++;
      }
      else
        combo = 0;
  }
  cout << cnt << ' ';
  cnt = 0;
  for (int c = 0; c < n; c++)
  {
    int combo = 0;
    for (int r = 0; r < n; r++)
      if (room[r][c] == '.')
      {
        if (++combo == 2)
          cnt++;
      }
      else
        combo = 0;
  }
  cout << cnt;

  return 0;
}
