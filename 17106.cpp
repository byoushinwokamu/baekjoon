#include <iostream>

using namespace std;

bool bingo[5][5];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  // for all board
  for (int t = 0; t < 33554432; t++) {
    // make bingo
    int d2 = 0;
    for (int i = 0; i < 25; i++) {
      bingo[i / 5][i % 5] = t & (1 << i);
      d2 += (t & (1 << i)) ? 1 : 0;
    }
    if (t % 3000000 == 0) {
      cout << "checked " << t << endl;
    }
    // check bingo
    bool quest;
    int ho = 0, ve = 0, di = 0;
    int hc = 0, vc = 0, dc = 0;
    int b3 = 0, e2 = 0;

    // check horizontal line
    for (int i = 0; i < 5; i++) {
      if (bingo[i][0] && bingo[i][1] && bingo[i][2] && bingo[i][3] &&
          bingo[i][4]) {
        ho += 1 << i;
        hc++;
      }
    }

    // check vertical line
    for (int i = 0; i < 5; i++) {
      if (bingo[0][i] && bingo[1][i] && bingo[2][i] && bingo[3][i] &&
          bingo[4][i]) {
        ve += 1 << i;
        vc++;
      }
    }

    // check diagonal line
    if (bingo[0][0] && bingo[1][1] && bingo[2][2] && bingo[3][3] && bingo[4][4])
      di += 1;
    if (bingo[4][0] && bingo[3][1] && bingo[2][2] && bingo[1][3] && bingo[0][4])
      di += 2;
    dc = (di % 2) + (di / 2);

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        // B3
        quest = bingo[i][j] && (ho & (1 << i) == 0) && (ve & (1 << j) == 0);
        if (i + j == 4)
          quest = quest || (bingo[i][j] && (di < 2));
        if (i == j)
          quest = quest || (bingo[i][j] && (di % 2 == 0));
        if (quest)
          b3++;

        // E2 E3
        quest = (ho & (1 << i) != 0) || (ve & (1 << j) != 0);
        if (i + j == 4)
          quest = quest || (di >= 2);
        if (i == j)
          quest = quest || (di % 2 == 1);
        if (quest)
          e2++;
      }
    }

    // A1
    quest = di < 2;
    if (bingo[0][0] != quest)
      continue;
    // A2 & A4 can't be equal
    if (bingo[1][0] == bingo[3][0])
      continue;
    // A3 can't be in vertical line 'cause of A2 & A4
    quest = ho & (1 << 2);
    if (bingo[2][0] != quest)
      continue;
    // A5 & E5 must be equal
    if (bingo[4][0] != bingo[4][4])
      continue;

    // B1 can't be false, if false, it becomes true
    if (!bingo[0][1])
      continue;
    // B2
    quest = ho * di * ve > 0;
    if (bingo[1][1] != quest)
      continue;
    // B3
    quest = b3 >= 5;
    if (bingo[2][1] != quest)
      continue;
    // B4
    quest = (ho & (1 << 1)) || (ve & (1 << 3));
    if (bingo[3][1] != quest)
      continue;
    // B5 우선 false 처리 true?
    if (bingo[4][1])
      continue;

    // C1
    quest = di % 2 == 1;
    if (bingo[0][2] != quest)
      continue;

    // C2 must be true
    if (!bingo[1][2])
      continue;

    // C3 must be true, but have some quest
    quest = (ho & (1 << 2)) || (ve & (1 << 2));
    if (!quest || !bingo[2][2])
      continue;

    // C4
    int c4 = 0;
    for (int i = 0; i < 5; i++)
      if (bingo[i][2])
        c4++;
    quest = c4 <= 3;
    if (quest != bingo[3][2])
      continue;

    // C5 doesn't matter

    // D1 & D4 must be equal
    if (bingo[0][3] != bingo[3][3])
      continue;

    // D2
    quest = d2 <= 17;
    if (bingo[1][3] != quest)
      continue;

    // D3
    quest = vc >= 2;
    if (bingo[2][3] != quest)
      continue;

    // D5
    quest = (dc + vc + hc) >= 3;
    if (bingo[4][3] != quest)
      continue;

    // E1 can't be in horizontal line 'cause B2 is true
    quest = /*(ho & (1 << 0)) || */ (ve & (1 << 4)) || (di / 2);
    if (bingo[0][4] != quest)
      continue;

    // E2
    quest = e2 % 2 == 0;
    if (bingo[1][4] != quest)
      continue;

    // E3
    quest = (25 - e2) >= 10;
    if (bingo[2][4] != quest)
      continue;

    // E4
    quest = di >= 0;
    if (bingo[3][4] != quest)
      continue;

    // print bingo
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << (bingo[i][j] ? '#' : '.');
      }
      cout << '\n';
    }
    cout << '\n';
  }

  cout << "terminated" << endl;
  return 0;
}