// BOJ 14003
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int a[1000001];
int longestlen[1000001];  // 해당 위치에서 가장 긴 증가하는 부분 수열의 길이
int smallestnum[1000001]; // 해당 길이를 longestlen으로 가지는 가장 작은 a[i]
int longestest;           // 가장 긴 longestlen

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  cin >> a[0];
  longestlen[0] = 1;
  smallestnum[1] = a[0];
  fill(smallestnum + 2, smallestnum + n, __INT32_MAX__);
  longestest = 1;
  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    longestlen[i] = 1;
    int len;
    for (len = longestest; len > 0; len--)
    {
      if (smallestnum[len] < a[i])
      {
        longestlen[i] = len + 1;
        break;
      }
    }
    // if (len + 1 >= longestest)
    smallestnum[len + 1] = min(smallestnum[len + 1], a[i]);
    longestest = max(longestest, longestlen[i]);
  }

  cout << longestest << '\n';
  for (int i = 1; i <= longestest; i++)
    cout << smallestnum[i] << ' ';

  return 0;
}
