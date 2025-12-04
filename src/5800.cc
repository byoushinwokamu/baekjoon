// BOJ 5800
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
  int k, n, mg;

  cin >> k;
  vector<int> v;
  for (int kk = 1; kk <= k; kk++)
  {
    mg = 0;
    cout << "Class " << kk << '\n';

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
      mg = max(mg, v[i + 1] - v[i]);

    cout << "Max " << (*v.rbegin()) << ", Min " << (*v.begin()) << ", Largest gap " << mg << '\n';
  }

  return 0;
}
