#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pp;

int n;
ll c;
vector<int> v(500000);
stack<int> st;
stack<int> sa; // 같은 키 사람의 수, 현재 카운트는 제외
int same;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (st.empty()) {
      st.push(i);
      same = 1;

    } else if (v[st.top()] > v[i]) { // shorter person
      st.push(i);
      sa.push(same);
      // c += same;
      c++;
      cout << 's' << 1 << '/';
      same = 1;

    } else if (v[st.top()] == v[i]) { // same person
      st.push(i);
      cout << '=' << same << '+' << (sa.empty() ? 0 : sa.top()) << '/';
      c += same++ + (sa.empty() ? 0 : sa.top());

    } else { // taller person
      while (!st.empty() && v[st.top()] < v[i]) {
        while (same--) {
          st.pop();
          c++;
        }
        if (sa.empty())
          same = 0;
        else
          same = sa.top(), sa.pop();
      }

      if (!st.empty()) {
        if (v[st.top()] == v[i]) {
          st.push(i);
          c += same++ + (sa.empty() ? 0 : sa.top());
        } else {
          st.push(i);
          sa.push(same);
          same = 1;
          c++;
        }
      } else {
        st.push(i);
        same = 1;
      }
    }
  }
  // cout << st.size() << endl;
  cout << endl << c << endl;

  return 0;
}
