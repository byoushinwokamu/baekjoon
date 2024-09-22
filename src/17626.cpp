#include <iostream>

using namespace std;

int arr[50001];
int sqr[224];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  for (int i = 1; i < 224; i++) {
    sqr[i] = i * i;
  }
  for (int i = 0; i < 50000; i++) {
    for (int j = 1; j < 224; j++) {
      if (i + sqr[j] > 50000)
        break;
      if (arr[i + sqr[j]] == 0 || arr[i + sqr[j]] > arr[i] + 1)
        arr[i + sqr[j]] = arr[i] + 1;
    }
  }

  int n;
  cin >> n;
  cout << arr[n];
  return 0;
}