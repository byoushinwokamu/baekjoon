#include <iostream>
#include <queue>

#define DIM 11
#define MAXBOXSIZE 1000000
using namespace std;

class Point;

queue<Point> q;
Point *du[DIM * 2];
int axissize[DIM];
int coeff[DIM];
int tmtcnt; // BFS에서 익은 토마토 개수
int tmt;    // 총 토마토 개수
int box[MAXBOXSIZE];
// 0은 안익은 토마토
//-1은 토마토 없음
// 1 이상은 토마토가 익는데 걸리는 날짜+1

class Point {
public:
  int *u;
  Point() {
    u = new int[DIM];
    for (int i = 0; i < DIM; i++)
      u[i] = 0;
  }
  Point(const Point &p) {
    u = new int[DIM];
    for (int i = 0; i < DIM; i++)
      u[i] = p.u[i];
  }

  Point operator+(Point p) {
    Point res;
    for (int i = 0; i < DIM; i++) {
      res.u[i] = this->u[i] + p.u[i];
      if (res.u[i] < 0 || res.u[i] >= axissize[i]) {
        res.u[0] = -1;
        return res;
      }
    }
    return res;
  }

  ~Point() { delete (u); }

  int getPos() {
    int pos = 0;
    for (int i = 0; i < DIM; i++) {
      pos += u[i] * coeff[i];
    }
    return pos;
  }
};

void getTomato() {
  int total = coeff[DIM - 1] * axissize[DIM - 1];
  for (int i = 0; i < total; i++) {
    cin >> box[i];
    if (box[i] != -1)
      tmt++;
    if (box[i] == 1) {
      int ii = i, dimm = DIM - 1;
      Point p;
      for (dimm; dimm >= 0; dimm--) {
        p.u[dimm] = ii / coeff[dimm];
        ii %= coeff[dimm];
      }
      q.push(p);
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  // get axis size of box
  int total = 1;
  for (int i = 0; i < DIM; i++) {
    cin >> axissize[i];
    du[2 * i] = new Point();
    du[2 * i]->u[i] = +1;
    du[2 * i + 1] = new Point();
    du[2 * i + 1]->u[i] = -1;
    coeff[i] = total;
    total *= axissize[i];
  }

  // get tomato infomation and enqueue
  getTomato();

  // do BFS
  int maxday = 1;
  while (!q.empty()) {
    Point pos = q.front();
    int day = box[pos.getPos()] + 1;
    tmtcnt++;
    q.pop();
    for (Point *d : du) {
      Point np = pos + *d;
      int poss = np.getPos();
      if (np.u[0] == -1)
        continue;
      if (box[poss] == 0) {
        box[poss] = day;
        q.push(np);
        maxday = maxday > day ? maxday : day;
      }
    }
  }

  cout << (tmt == tmtcnt ? maxday - 1 : -1);
  return 0;
}