#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int score = 0;
  int streak = 0;
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    string s;
    score = 0;
    streak = 0;
    cin >> s;
    for (char c : s) {
      if (c == 'O') {
        streak++;
        score += streak;
      } else
        streak = 0;
    }
    cout << score << "\n";
  }

  return 0;
}