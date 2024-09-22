#include <iostream>
#include <stack>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  stack<int> st;
  int k, n;
  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> n;
    n ? st.push(n) : st.pop();
  }

  int sum = 0;
  while (!st.empty()) {
    sum += st.top();
    st.pop();
  }
  cout << sum;
  return 0;
}