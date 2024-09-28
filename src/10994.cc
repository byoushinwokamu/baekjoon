#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
가로 4n-3 세로 4n-3
끝행(0행 4n-4행) = 별 4n-3개 연속
가운데행(2n-2행) = 별 2n-1개를 한칸간격
홀수행(2k-1 또는 4n-4-2k-1) 별 k개 한칸간격으로 찍고
4n-1-2(2k-1) =/= 4n-4k-1개
빈칸 이후 별 k개 한칸간격
짝수행(2k 또는 4n-4-2k) 별 k개 한칸간격으로 찍고
한칸띄워서 별 4n-3-4k개 연속 이후 k개 한칸간격: 끝 가운데도 동일
*/

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < 4 * n - 3; i++) {
    if (i % 2) {
      int k = (i < 2 * n - 2 ? (i + 1) / 2 : (4 * n - i - 3) / 2);
      for (int j = 0; j < k; j++)
        cout << "* ";
      for (int j = 0; j < 4 * n - 4 * k - 2; j++)
        cout << ' ';
      for (int j = 0; j < k; j++)
        cout << "* ";
    } else {
      int k = (i < 2 * n - 2 ? i / 2 : (4 * n - i - 4) / 2);
      for (int j = 0; j < k; j++)
        cout << "* ";
      for (int j = 0; j < 4 * n - 4 * k - 3; j++)
        cout << '*';
      cout << ' ';
      for (int j = 0; j < k; j++)
        cout << "* ";
    }
    cout << '\n';
  }

  return 0;
}