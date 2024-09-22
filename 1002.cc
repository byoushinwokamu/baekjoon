#include <iostream>
#include <vector>

using namespace std;

int sq(int a) { return a * a; }
int disq(int x1, int x2, int y1, int y2) { return sq(x1 - x2) + sq(y1 - y2); }

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int x1, x2, y1, y2, r1, r2;
  int t, di, tem;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (r1 < r2)
      tem = r1, r1 = r2, r2 = tem;
    di = disq(x1, x2, y1, y2);
    if (x1 == x2 && y1 == y2) {
      if (r1 == r2) // 두 원 일치
        cout << -1 << '\n';
      else // 동심원인데 지름 다름
        cout << 0 << '\n';
    } else if (di > sq(r1 + r2)) // 반지름합보다 거리가 더 길다(멀다, 안겹침)
      cout << 0 << '\n';
    else if (di == sq(r1 + r2)) // 반지름합과 거리가 같다(외접)
      cout << 1 << '\n';
    else {             // di < sq(r1 + r2) :: 경우의수가 많다
      if (di > sq(r1)) // 외접보단 가까우나 작은중심이 큰원 안으로 들어가지 않음
        cout << 2 << '\n';
      else { // 작은원의 중심이 큰원 안으로 들어감 if (r1 < 2 * r2)
        if (sq(r1 - r2) == di) // 내접
          cout << 1 << '\n';
        else if (sq(r1 - r2) > di) // 안접함
          cout << 0 << '\n';
        else
          cout << 2 << '\n';
      }
    }
  }

  return 0;
}