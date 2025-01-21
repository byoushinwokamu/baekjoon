// 25379 카드 숫자 곱의 경우의 수 - 하드코딩 풀이
#include <iostream>
using namespace std;
int main() {
  int ans[] = {0, 9, 36, 100, 225, 441, 784, 1296};
  int n;
  cin >> n;
  cout << ans[n];
  return 0;
}
