#include <iostream>
#include <queue>

#define DIM 2
#define MAXBOXSIZE 1000000
using namespace std;

int du[DIM * 2];
int box[MAXBOXSIZE];
// 0은 안익은 토마토
//-1은 토마토 없음
// 1 이상은 토마토가 익는데 걸리는 날짜+1

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  queue<int> q;

  // get size of box
  int size[DIM];
  int total = 1;
  for (int i = 0; i < DIM; i++) {
    cin >> size[i];
    du[2 * i] = total;
    du[2 * i + 1] = -total;
    total *= size[i];
  }

  // get tomato infomation and enqueue
  for (int i = 0; i < total; i++) {
    cin >> box[i];
    if (box[i] == 1)
      q.push(i);
  }

  // bfs
  int maxday = -1;
  while (!q.empty()) {
    int pos = q.front();
    int day = box[pos] + 1;
    q.pop();
    for (int d : du) {
      if (pos + d >= total || pos + d < 0)
        continue;
      if (box[pos + d] == 0) {
        box[pos + d] = day;
        q.push(pos + d);
        maxday = maxday > day ? maxday : day;
      }
    }
  }

  bool allripe = true;
  for (int i = 0; i < total; i++)
    if (box[i] == 0)
      allripe = false;
  for (int i = 0; i < total; i++)
    cout << box[i] << " ";
  cout << endl << (allripe ? maxday - 1 : -1);
  return 0;
}