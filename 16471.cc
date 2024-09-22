#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> carda(n), cardb(n);
  for (int i = 0; i < n; i++)
    cin >> carda[i];
  for (int i = 0; i < n; i++)
    cin >> cardb[i];
  sort(carda.begin(), carda.end());
  sort(cardb.begin(), cardb.end());

  auto it = carda.begin();
  auto enem = cardb.begin();
  int sc = 0;
  for (enem; enem != cardb.end(); enem++) {
    if (it == carda.end())
      break;
    if (*it < *enem)
      sc++, it++;
  }
  if (sc >= (n + 1) / 2)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}