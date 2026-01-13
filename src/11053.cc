// BOJ 11053
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int a[1000];
int longest[1000];
int longestest = 1;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  cin >> a[0];
  longest[0] = 1;

  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    longest[i] = 1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (a[j] < a[i])
        longest[i] = max(longest[i], longest[j] + 1);
    }
    longestest = max(longestest, longest[i]);
  }

  cout << longestest;

  return 0;
}
