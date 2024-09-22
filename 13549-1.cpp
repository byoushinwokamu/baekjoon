#include <deque>
#include <iostream>

using namespace std;

int vis[222222];
int n, k;
deque<int> q;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  q.push_back(n);
  vis[n] = 1;

  while (!q.empty()) {
    int now = q.front();
    q.pop_front();
    if (now == k) {
      cout << vis[now] - 1;
      return 0;
    }
    if (now < 100000 && vis[now * 2] == 0) {
      q.push_front(now * 2);
      vis[now * 2] = vis[now];
    }
    if (now > 0 && vis[now - 1] == 0) {
      q.push_back(now - 1);
      vis[now - 1] = vis[now] + 1;
    }
    if (now < 100000 && vis[now + 1] == 0) {
      q.push_back(now + 1);
      vis[now + 1] = vis[now] + 1;
    }
  }

  return 0;
}