// BOJ 14003-1
#include <algorithm>
#include <iostream>
#include <stack>
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
  vector<int> lg(n);
  vector<int> sm(n + 1, 1000000001);
  vector<int> ap(n);
  int lgg = 1;

  cin >> a[0];
  lg[0] = 1;
  sm[1] = a[0];
  ap[0] = 1;
  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    lg[i] = lower_bound(sm.begin() + 1, sm.begin() + lgg + 1, a[i]) - sm.begin();
    sm[lg[i]] = min(sm[lg[i]], a[i]);
    ap[i] = lg[i];
    lgg = max(lg[i], lgg);
  }
  cout << lgg << '\n';

  stack<int> st;
  int cur = n;
  for (lgg; lgg > 0; lgg--)
  {
    while (ap[--cur] != lgg);
    st.push(a[cur]);
  }
  while (!st.empty()) cout << st.top() << ' ', st.pop();

  return 0;
}
