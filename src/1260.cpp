#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int adj[1000][1000];
int vdfs[1000];
int vbfs[1000];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, v;
  cin >> n >> m >> v;
  v--;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1][b - 1]++;
    adj[b - 1][a - 1]++;
  }

  // dfs
  stack<int> st;
  vdfs[v]++;
  cout << v + 1 << " ";
  st.push(v);
  while (!st.empty()) {
    int now = st.top();
    for (int i = 0; i < n; i++) {
      if (adj[now][i] && !vdfs[i]) {
        vdfs[i]++;
        cout << i + 1 << " ";
        st.push(i);
        break;
      }
    }
    if (now == st.top())
      st.pop();
  }
  cout << '\n';

  // bfs
  queue<int> q;
  vbfs[v]++;
  cout << v + 1 << " ";
  q.push(v);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (adj[now][i] && !vbfs[i]) {
        vbfs[i]++;
        cout << i + 1 << " ";
        q.push(i);
      }
    }
  }

  return 0;
}