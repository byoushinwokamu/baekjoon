#include <iostream>
#include <queue>

using namespace std;

int mapp[2500];
int w, h, a; // width height area
queue<int> q;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  a = w * h;
  while (a != 0) {
    for (int i = 0; i < a; i++)
      cin >> mapp[i];

    int island = 0;
    for (int i = 0; i < a; i++) {
      if (mapp[i] == 1) {
        island++;
        q.push(i);
        mapp[i] = 2;
      }
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now >= h && mapp[now - h] == 1) { // 위
          mapp[now - h] = 2;
          q.push(now - h);
        }
        if (now < a - h && mapp[now + h] == 1) { // 아래
          mapp[now + h] = 2;
          q.push(now + h);
        }
        if (now % h > 0 && mapp[now - 1] == 1) { // 왼쪽
          mapp[now - 1] = 2;
          q.push(now - 1);
        }
        if (now % h < h - 1 && mapp[now + 1] == 1) { // 오른쪽
          mapp[now + 1] = 2;
          q.push(now + 1);
        }
        // 좌상
        if (now >= h && now % h > 0 && mapp[now - h - 1] == 1) {
          mapp[now - h - 1] = 2;
          q.push(now - h - 1);
        }
        // 우하
        if (now < a - h && now % h < h - 1 && mapp[now + h + 1] == 1) {
          mapp[now + h + 1] = 2;
          q.push(now + h + 1);
        }
        // 우상
        if (now >= h && now % h < h - 1 && mapp[now - h + 1] == 1) {
          mapp[now - h + 1] = 2;
          q.push(now - h + 1);
        }
        // 좌하
        if (now < a - h && now % h > 0 && mapp[now + h - 1] == 1) {
          mapp[now + h - 1] = 2;
          q.push(now + h - 1);
        }
      }
    }
    cout << island << '\n';
    cin >> h >> w;
    a = w * h;
  }

  return 0;
}