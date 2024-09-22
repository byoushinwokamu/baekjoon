#include <iostream>
#include <queue>

using namespace std;

int sb[30][30][30];
// -2는 벽, -1은 미탐색 공간, 0이상은 도달시간

class Point {
public:
  int x;
  int y;
  int z;
  Point() {}
  Point(int a, int b, int c) : x(a), y(b), z(c) {}
  Point operator+(const Point &p) {
    Point r;
    r.x = x + p.x;
    r.y = y + p.y;
    r.z = z + p.z;
    return r;
  }
  bool operator==(const Point &p) {
    return (x == p.x && y == p.y && z == p.z) ? true : false;
  }
  int getsb() { return sb[x][y][z]; }
  void setsb(int time) { sb[x][y][z] = time; }
};

Point dp[6] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
               {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  while (true) {
    int l, r, c;
    Point start, end;
    char input[31];
    queue<Point> q;
    cin >> l >> r >> c;
    if (l + r + c == 0)
      break;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        cin >> input;
        for (int k = 0; k < c; k++) {
          switch (input[k]) {
          case 'S':
            start.x = i;
            start.y = j;
            start.z = k;
            sb[i][j][k] = 0;
            break;
          case 'E':
            end.x = i;
            end.y = j;
            end.z = k;
            sb[i][j][k] = -1;
            break;
          case '.':
            sb[i][j][k] = -1;
            break;
          case '#':
            sb[i][j][k] = -2;
            break;
          }
        }
      }
    }
    q.push(start);
    bool trapped = true;
    while (!q.empty()) {
      Point now = q.front();
      int time = now.getsb();
      if (now == end) {
        cout << "Escaped in " << time << " minute(s).\n";
        trapped = false;
        break;
      }
      q.pop();
      for (Point d : dp) {
        Point nextp = now + d;
        if (nextp.x < 0 || nextp.y < 0 || nextp.z < 0 || nextp.x >= l ||
            nextp.y >= r || nextp.z >= c)
          continue;
        if (nextp.getsb() == -1) {
          nextp.setsb(time + 1);
          q.push(nextp);
        }
      }
    }
    if (trapped)
      cout << "Trapped!\n";
    while (!q.empty())
      q.pop();
  }
  return 0;
}