// BOJ 1377
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
// vector<int> last(1000001); // stores last appearance index

/*
버블정렬이 끝나는 시점.
전체 목록에서 오른쪽으로 이동할 놈의 개수 +1이 정답.

이 아닌가보다.
*/

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, t, cnt = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(a);
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++)
  {
    if (a[i] > b[i])
      cnt++;
  }
  cout << cnt + 1;

  return 0;
}
