#include <iostream>
#include <queue>

using namespace std;

bool notliableP[50]; // party
bool visitP[50];
bool notliableM[50]; // man
bool adj[50][50];    // [party][man]

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int knower;
  cin >> knower;
  queue<pair<int, char>> q; // char : p / m
  for (int i = 0; i < knower; i++) {
    int a;
    cin >> a;
    notliableM[a - 1] = true;
  }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int b;
      cin >> b;
      adj[i][b - 1] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (notliableM[i]) {
      q.push(make_pair(i, 'm'));
    }
  }
  while (!q.empty()) {
    int now = q.front().first;
    char ntype = q.front().second;
    q.pop();
    if (ntype == 'm') { // fetched man
      for (int i = 0; i < m; i++) {
        if (adj[i][now] && !visitP[i]) {
          notliableP[i] = true;
          visitP[i] = true;
          q.push(make_pair(i, 'p'));
        }
      }
    } else { // fetched party
      for (int i = 0; i < n; i++) {
        if (adj[now][i]) {
          notliableM[i] = true;
          q.push(make_pair(i, 'm'));
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < m; i++)
    if (!notliableP[i])
      cnt++;
  cout << cnt;
  return 0;
}