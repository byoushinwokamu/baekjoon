// BOJ 10942
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m, a, b;
vector<vector<bool>> pal(2000, vector<bool>(2000));
vector<vector<bool>> nopal(2000, vector<bool>(2000));
int seq[2000];

bool ispal(int s, int e)
{
  if (s == e) return true;
  else if (e - s == 1) return seq[s] == seq[e];
  else if (pal[s][e]) return true;
  else if (nopal[s][e]) return false;
  else
  {
    bool res = (seq[s] == seq[e]) && ispal(s + 1, e - 1);
    pal[s][e] = res;
    nopal[s][e] = !res;
    return res;
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> seq[i];

  cin >> m;
  for (int mm = 0; mm < m; mm++)
  {
    cin >> a >> b;
    cout << (ispal(a - 1, b - 1) ? "1\n" : "0\n");
  }

  return 0;
}
