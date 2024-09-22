#include <iostream>
#include <list>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  list<int> li;
  for (int i = 1; i <= n; i++)
    li.push_back(i);

  list<int>::iterator iter = li.begin();

  cout << '<';
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < k - 1; j++) {
      iter++;
      if (iter == li.end())
        iter = li.begin();
    }
    cout << *iter << ", ";
    iter = li.erase(iter);
    if (iter == li.end())
      iter = li.begin();
  }
  iter = li.begin();
  cout << *iter << ">";
  return 0;
}