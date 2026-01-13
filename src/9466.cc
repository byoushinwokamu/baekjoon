// BOJ 9466
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> visit(100001);
vector<bool> insider(100001);
vector<bool> outsider(100001);
vector<int> adj(100001);
int inssa;

int dfs(int now) // retval: cycle point
{
  if (insider[now] || outsider[now]) return 0; // 이미 탐색 완료한 학생

  if (visit[now]) // CP 도달
  {
    insider[now] = true;
    inssa++;
    return now;
  }
  visit[now] = true;

  int cp = dfs(adj[now]); // 다음 학생 탐색

  if (cp == now) // 사이클 다 표시함
  {
    return 0;
  }
  else if (cp) // 사이클 표시 중
  {
    insider[now] = true;
    inssa++;
    return cp;
  }
  else // 사이클 아님
  {
    outsider[now] = true;
    return 0;
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    fill(outsider.begin(), outsider.end(), false);
    fill(insider.begin(), insider.end(), false);
    fill(adj.begin(), adj.end(), 0);
    inssa = 0;
    for (int i = 1; i <= n; i++) cin >> adj[i];
    for (int i = 1; i <= n; i++)
    {
      if (insider[i] || outsider[i]) continue;
      fill(visit.begin(), visit.end(), false);
      dfs(i);
    }
    cout << n - inssa << '\n';
  }

  return 0;
}
