// BOJ 1655
#include <algorithm>
#include <iostream>
#include <queue>
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
  int n, a;
  cin >> n;

  priority_queue<int> maxheap;
  priority_queue<int, vector<int>, greater<int>> minheap;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if ((i & 1) == 0)
      maxheap.push(a);
    else
      minheap.push(a);
    if (!minheap.empty() && (maxheap.top() > minheap.top()))
    {
      int t = maxheap.top();
      maxheap.pop();
      maxheap.push(minheap.top());
      minheap.pop();
      minheap.push(t);
    }
    cout << maxheap.top() << '\n';
  }

  return 0;
}
