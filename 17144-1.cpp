#include <iostream>

using namespace std;
int room[2500];
int dr[2500];
int r, c, t;

void printroom() {
  // for debug: print room
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int pos = i * 50 + j;
      cout << room[pos] + dr[pos] << " ";
    }
    cout << endl;
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> r >> c >> t;
  int pu = -1, pl = -1; // purifier upper, lower

  // input data
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int pos = i * 50 + j;
      cin >> room[pos];
      if (room[pos] < 0) { // 공기청정기
        if (pu < 0)
          pu = pos;
        else
          pl = pos;
      }
    }
  }

  for (int i = 0; i < t; i++) {
    // first half of second
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
        int now = j * 50 + k;
        int dust = room[now] / 5;
        if (dust == 0)
          continue;
        if (now >= 50 && now - 50 != pl) { // not first row
          dr[now - 50] += dust;
          dr[now] -= dust;
        }
        if (now / 50 < r - 1 && now + 50 != pu) { // not last row
          dr[now + 50] += dust;
          dr[now] -= dust;
        }
        if (now % 50 != 0 && now != pu + 1 &&
            now != pl + 1) { // not first column
          dr[now - 1] += dust;
          dr[now] -= dust;
        }
        if (now % 50 < c - 1) { // not last column
          dr[now + 1] += dust;
          dr[now] -= dust;
        }
        room[now] += dr[now];
        dr[now] = 0;
      }
    }

    // second half of second
    // upper purifier
    int now = pu - 50;
    while (now > 0) { // up
      room[now] = room[now - 50] + dr[now - 50];
      dr[now] = 0;
      now -= 50;
    }
    // now==0
    while (now < c - 1) { // right
      room[now] = room[now + 1] + dr[now + 1];
      dr[now] = 0;
      now += 1;
    }
    // now==c-1
    while (now < pu) { // down
      room[now] = room[now + 50] + dr[now + 50];
      dr[now] = 0;
      now += 50;
    }
    while (now > pu + 1) { // left
      room[now] = room[now - 1] + dr[now - 1];
      dr[now] = 0;
      now -= 1;
    }
    room[now] = 0;
    dr[now] = 0;

    // lower purifier
    now = pl + 50;
    while (now < (r - 1) * 50) { // down
      room[now] = room[now + 50] + dr[now + 50];
      dr[now] = 0;
      now += 50;
    }
    while (now % 50 < c - 1) { // right
      room[now] = room[now + 1] + dr[now + 1];
      dr[now] = 0;
      now += 1;
    }
    while (now > pl + 50) { // up
      room[now] = room[now - 50] + dr[now - 50];
      dr[now] = 0;
      now -= 50;
    }
    while (now > pl + 1) { // left
      room[now] = room[now - 1] + dr[now - 1];
      dr[now] = 0;
      now -= 1;
    }
    room[now] = 0;
    dr[now] = 0;
  } // for each second loop

  // count dust
  printroom();
  int dust = 2;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int pos = i * 50 + j;
      dust += room[pos] + dr[pos];
    }
  }
  cout << dust;
  return 0;
}