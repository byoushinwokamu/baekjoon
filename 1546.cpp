#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int score, avg = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> score;
    m = (m > score ? m : score);
    avg += score;
  }
  double average = (double)avg / (double)n;
  average *= (100 / (double)m);
  cout << average;
  return 0;
}