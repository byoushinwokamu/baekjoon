// BOJ 14003
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

vector<int> a;  // 원본 수열
vector<int> p;  // a_i가 sm의 몇 번재 칸에 저장되었는지
vector<int> sm; // lg값의 최소 등장 a

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  a.resize(n);
  p.resize(n);
  sm.reserve(n);
  int lgg = 1;
  cin >> a[0];
  sm.push_back(a[0]);
  p[0] = 0;
  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    if (sm.back() < a[i])
    {
      p[i] = sm.size();
      sm.push_back(a[i]);
    }
    else
    {
      auto it = lower_bound(sm.begin(), sm.end(), a[i]);
      *it = a[i], p[i] = it - sm.begin();
    }
  }
  cout << sm.size() << '\n';

  stack<int> st;
  int target = sm.size() - 1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (target == p[i]) target--, st.push(a[i]);
  }
  while (!st.empty()) cout << st.top() << ' ', st.pop();

  return 0;
}
