#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int compare(const void *a, const void *b) {
  if (strlen((char *)a) == strlen((char *)b)) {
    return strcmp((char *)a, (char *)b);
  } else
    return strlen((char *)a) - strlen((char *)b);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  char str[20000][51];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> str[i];

  qsort(str, n, sizeof(char) * 51, compare);

  for (int i = 0; i < n; i++) {
    if (i > 0 && strcmp(str[i], str[i - 1]) == 0)
      continue;
    cout << str[i] << '\n';
  }

  return 0;
}