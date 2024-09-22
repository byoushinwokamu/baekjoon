#include <iostream>
#define MAXX 67108864

using namespace std;

char bt[MAXX];

void pre(int n) {
  cout << bt[n];
  if (2 * n + 1 < MAXX && bt[2 * n + 1] != 0)
    pre(2 * n + 1);
  if (2 * n + 2 < MAXX && bt[2 * n + 2] != 0)
    pre(2 * n + 2);
}
void in(int n) {
  if (2 * n + 1 < MAXX && bt[2 * n + 1] != 0)
    in(2 * n + 1);
  cout << bt[n];
  if (2 * n + 2 < MAXX && bt[2 * n + 2] != 0)
    in(2 * n + 2);
}
void post(int n) {
  if (2 * n + 1 < MAXX && bt[2 * n + 1] != 0)
    post(2 * n + 1);
  if (2 * n + 2 < MAXX && bt[2 * n + 2] != 0)
    post(2 * n + 2);
  cout << bt[n];
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  char t1, t2, t3;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t1 >> t2 >> t3;
    if (i == 0) {
      bt[0] = t1;
      bt[1] = t2 != '.' ? t2 : 0;
      bt[2] = t3 != '.' ? t3 : 0;
    } else {
      int found = -1;
      for (int j = 0; j < MAXX; j++)
        if (bt[j] == t1)
          found = j;
      bt[found] = t1;
      bt[2 * found + 1] = t2 != '.' ? t2 : 0;
      bt[2 * found + 2] = t3 != '.' ? t3 : 0;
    }
  }
  pre(0);
  cout << '\n';
  in(0);
  cout << '\n';
  post(0);

  return 0;
}