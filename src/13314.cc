// BOJ 13314
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

#include <stdio.h>
#include <stdlib.h>

#define WRONG                     \
  {                               \
    printf("Count is %d\n", cnt); \
    exit(cnt);                    \
  }
#define CORRECT   \
  {               \
    printf("AC"); \
    exit(cnt);    \
  }
using namespace std;

const int MX = 105;

int D[MX][MX], E[MX][MX];
int cnt = 0;

int main()
{
  int N;
  scanf("%d", &N);
  if (N < 1 || N > 100) WRONG;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      scanf("%d", D[i] + j);
      if (D[i][j] < 0) WRONG;
      if (i == j && D[i][j] != 0 || D[i][j] > 10000) WRONG;
      E[i][j] = D[i][j];
    }
  }
  for (int k = 1; k < N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
      }
    }
  }
  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        E[i][j] = min(E[i][k] + E[k][j], E[i][j]);
      }
    }
  }
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (D[i][j] != E[i][j]) cnt++;
    }
  }
  cout << "INPUT IS VALID\n";
  if (cnt >= 9700) CORRECT
  else WRONG;
}
