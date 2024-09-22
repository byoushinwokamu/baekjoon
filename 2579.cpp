#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int stair[301];
int score[301][2];
// 2nd index: 연속으로 밟은 계단 수

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> stair[i + 1];

  score[1][0] = 0;
  score[1][1] = stair[1];

  score[2][0] = stair[2];
  score[2][1] = stair[1] + stair[2];

  for (int i = 3; i <= n; i++) {
    score[i][0] = max(score[i - 2][0], score[i - 2][1]) + stair[i];
    score[i][1] = score[i - 1][0] + stair[i];
  }
  cout << max(score[n][0], score[n][1]);

  return 0;
}