#include <iostream>

using namespace std;

typedef pair<int, int> P;

bool compare(const P &p1, const P &p2) {
  return p1.first > p2.first && p1.second > p2.second;
}

P dunch[50];
int dlevel[50];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dunch[i].first >> dunch[i].second;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i != j && compare(dunch[i], dunch[j]))
        dlevel[j]++;
    }
  for (int i = 0; i < n; i++)
    cout << dlevel[i] + 1 << " ";

  return 0;
}