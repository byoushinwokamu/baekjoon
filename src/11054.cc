// BOJ 11054
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> asc(n); // 증가하는 최장 길이(증가중)
  int ascest = 0;
  vector<int> biton(n); // 바이토닉 최장 길이(감소중)
  int bitonest = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    asc[i] = 1, biton[i] = 1;
    for (int j = i - 1; j >= 0; j--)
      if (a[j] > a[i]) biton[i] = max({biton[j] + 1, biton[i], asc[i], asc[j] + 1});
      else if (a[j] < a[i]) asc[i] = max(asc[j] + 1, asc[i]);
    bitonest = max(bitonest, biton[i]);
  }
  cout << bitonest;

  return 0;
}
