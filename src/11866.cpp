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
  auto iter = li.begin();
  for (int i = 0; i < k - 1; i++)
    iter++;
  cout << "<" << *iter;
  iter = li.erase(iter);
  if (iter == li.end())
    iter = li.begin();
  while (!li.empty()) {
    for (int i = 0; i < k - 1; i++) {
      iter++;
      if (iter == li.end())
        iter = li.begin();
    }
    cout << ", " << *iter;
    iter = li.erase(iter);
    if (iter == li.end())
      iter = li.begin();
  }
  cout << ">";

  return 0;
}