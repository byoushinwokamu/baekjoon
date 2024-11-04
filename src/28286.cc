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
int n, k;
int cnt, mct;
vector<int> sk(20), ori(21), idx(20);
stack<int> tem;

void push(int p) {
  tem.push(idx[n - 1]);
  for (int i = n - 1; i > p; i--) {
    idx[i] = idx[i - 1];
  }
  idx[p] = 20;
}
void push_rb(int p) {
  for (int i = p; i < n - 1; i++) {
    idx[i] = idx[i + 1];
  }
  idx[n - 1] = tem.top();
  tem.pop();
}
void pull(int p) {
  tem.push(idx[p]);
  for (int i = p; i < n - 1; i++) {
    idx[i] = idx[i + 1];
  }
  idx[n - 1] = 20;
}
void pull_rb(int p) {
  for (int i = n - 1; i > p; i--) {
    idx[i] = idx[i - 1];
  }
  idx[p] = tem.top();
  tem.pop();
}

void dfs(int nk) {
  // check
  cnt = 0;
  // for (int i = 0; i < n; i++)
  //   cout << sk[i] << ' ';
  // cout << '\n';
  // for (int i = 0; i < n; i++)
  //   cout << ori[idx[i]] << ' ';
  // cout << '\n';

  for (int a = 0; a < n; a++) {
    if (ori[idx[a]] == sk[a])
      cnt++;
  }
  // cout << cnt << "\n\n";
  mct = max(mct, cnt);
  if (nk == k)
    return;
  else {
    for (int i = 0; i < n; i++) {
      push(i);
      dfs(nk + 1);
      push_rb(i);
    }
    for (int i = 0; i < n; i++) {
      pull(i);
      dfs(nk + 1);
      pull_rb(i);
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> sk[i];
  for (int i = 0; i < n; i++)
    cin >> ori[i], idx[i] = i;

  dfs(0);
  cout << mct;

  return 0;
}
