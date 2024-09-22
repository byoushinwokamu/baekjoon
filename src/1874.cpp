#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string result;
  int input;
  int cur = 1;
  stack<int> st;
  st.push(0);
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (st.top() > input) {
      cout << "NO";
      return 0;
    }
    for (cur; cur <= input; cur++) {
      st.push(cur);
      result += "+\n";
    }
    st.pop();
    result += "-\n";
  }
  cout << result;
  return 0;
}