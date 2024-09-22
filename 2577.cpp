#include <cstring>
#include <iostream>

using namespace std;
int c[10];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  int res = 1;
  cin >> n;
  res *= n;
  cin >> n;
  res *= n;
  cin >> n;
  res *= n;
  char s[20];
  sprintf(s, "%d", res);
  n = strlen(s);
  for (int i = 0; i < n; i++)
    c[static_cast<int>(s[i]) - 48]++;
  for (int i = 0; i < 10; i++)
    cout << c[i] << "\n";
  return 0;
}