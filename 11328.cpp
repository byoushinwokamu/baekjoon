#include <cstring>
#include <iostream>

using namespace std;

int compare(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  char str1[1000], str2[1000];
  for (int i = 0; i < n; i++) {
    cin >> str1 >> str2;
    qsort(str1, strlen(str1), sizeof(char), compare);
    qsort(str2, strlen(str1), sizeof(char), compare);
    cout << (strcmp(str1, str2) ? "Impossible\n" : "Possible\n");
  }
}