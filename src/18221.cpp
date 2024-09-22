#include <cmath>
#include <iostream>

using namespace std;

int room[1000][1000];

double dis(double a1, double a2, double b1, double b2) {
  return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int s1, s2, p1, p2; // seongyu and professor
  int rec[4][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> room[i][j];
      if (room[i][j] == 2)
        s1 = i, s2 = j;
      if (room[i][j] == 5)
        p1 = i, p2 = j;
    }
  }
  if (dis(s1, p1, s2, p2) < 5)
    cout << 0;
  else {
    rec[0][0] = s1 < p1 ? s1 : p1;
    rec[0][1] = s2 < p2 ? s2 : p2;
    rec[1][0] = s1 > p1 ? s1 : p1;
    rec[1][1] = s2 < p2 ? s2 : p2;
    rec[2][0] = s1 < p1 ? s1 : p1;
    rec[2][1] = s2 > p2 ? s2 : p2;
    rec[3][0] = s1 > p1 ? s1 : p1;
    rec[3][1] = s2 > p2 ? s2 : p2;
    int cnt = 0;
    for (int i = rec[0][0]; i <= rec[3][0]; i++) {
      for (int j = rec[0][1]; j <= rec[3][1]; j++) {
        if (room[i][j] == 1)
          cnt++;
      }
    }
    if (cnt >= 3)
      cout << 1;
    else
      cout << 0;
  }

  return 0;
}