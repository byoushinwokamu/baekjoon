#include <iostream>
#include <queue>

#define DIM 11
#define MAXBOXSIZE 1000000
using namespace std;

int du[DIM * 2];
int axissize[DIM];
int coeff[DIM + 1];
int tmtcnt; // BFS에서 익은 토마토 개수
int tmt;    // 총 토마토 개수
int box[MAXBOXSIZE];
// 0은 안익은 토마토
//-1은 토마토 없음
// 1 이상은 토마토가 익는데 걸리는 날짜+1

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  // get axis size of box
  int total = 1;
  for (int i = 0; i < DIM; i++) {
    cin >> axissize[i];
    du[2 * i] = +total;
    du[2 * i + 1] = -total;
    coeff[i] = total;
    total *= axissize[i];
  }
  coeff[DIM] = total;

  // get tomato infomation and enqueue
  queue<int> q;
  for (int i = 0; i < coeff[DIM]; i++) {
    cin >> box[i];
    if (box[i] != -1)
      tmt++;
    if (box[i] == 1)
      q.push(i);
  }

  // do BFS
  int maxday = 1;
  while (!q.empty()) {
    int nowpos = q.front();
    int nextday = box[nowpos] + 1;
    tmtcnt++;
    q.pop();
    for (int i = 0; i < 2 * DIM; i++) {
      int nextpos = nowpos + du[i];
      int upperdimco = coeff[i / 2 + 1];

      // check validity of pos
      if (nextpos < 0 || nextpos >= coeff[DIM - 1] * axissize[DIM - 1])
        continue;
      if (nowpos / upperdimco != nextpos / upperdimco)
        continue;

      if (box[nextpos] == 0) {
        box[nextpos] = nextday;
        q.push(nextpos);
        maxday = maxday > nextday ? maxday : nextday;
      }
    }
  }

  cout << (tmt == tmtcnt ? maxday - 1 : -1);
  return 0;
}