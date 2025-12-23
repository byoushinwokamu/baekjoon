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

vector<bool> visit;
vector<bool> visit_temp;
vector<int> student;
int inssa, assa;

int dfs(int now) // retval: cycle point
{
  visit[now] = true;

  if (now == student[now]) // solo team
  {
    inssa++;
    return now;
  }

  if (visit_temp[now]) // cycle point 도달
  {
    inssa++;
    return now;
  }

  visit_temp[now] = true;
  int cp = dfs(student[now]); // dfs해서 사이클인지 아닌지 알아옴

  if (cp == -1) // no cycle
    return -1;
  else if (cp == now) // cycle all marked
    return -1;
  else // cycle marking
  {
    inssa++;
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
    visit.clear();
    visit.resize(n);
    visit_temp.clear();
    visit_temp.resize(n);
    student.resize(n);

    for (int i = 0; i < n; i++)
    {
      cin >> student[i];
      student[i]--;
    }

    inssa = 0;
    for (int i = 0; i < n; i++)
      if (!visit[i])
        dfs(i);

    cout << n - inssa << '\n';
  }

  return 0;
}
