#include <iostream>

using namespace std;

int compare(const void *a, const void *b) {
  return *(const int *)a > *(const int *)b ? 1 : -1;
}

int arr[1000002];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  int input;

  int x;
  int count = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    arr[input] = 1;
  }
  cin >> x;

  for (int i = 1; i < 500000; i++)
    if (x - i < 1000001 && x - i > 0)
      if (arr[i] && arr[x - i])
        count++;
  cout << count / 2;
}