#include <iostream>
#include <set>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int k, p;
    char op;
    cin >> k;
    multiset<int> ms;
    for (int i = 0; i < k; i++) {
      cin >> op >> p;
      if (op == 'I')
        ms.insert(p);
      else if (ms.empty())
        continue;
      else if (p == -1)
        ms.erase(ms.begin());
      else
        ms.erase(--ms.end());
    }
    if (ms.empty())
      cout << "EMPTY\n";
    else
      cout << *(--ms.end()) << " " << *ms.begin() << '\n';
  }

  return 0;
}