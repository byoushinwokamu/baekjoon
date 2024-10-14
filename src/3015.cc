#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define fi first
#define se second
typedef long long ll;

using namespace std;

int n, c;
vector<int> v(500000);
stack<int> st;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (st.empty())
      st.push(i);
    else if (v[st.top()] > v[i])
      st.push(i), c++;
    else if (v[st.top()] == v[i]) {
      ;
    } else {
      while (!st.empty() && v[st.top()] <= v[i]) {
        st.pop(), c++;
      }
      if (!st.empty())
        c++;
      st.push(i);
    }
  }
  // cout << st.size() << endl;
  cout << c;

  return 0;
}
