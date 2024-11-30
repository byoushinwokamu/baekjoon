#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define hp first
#define atk second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n;
vector<pp> egg;
int maxcrk;

void dfs(int now, int crk) {
  if (now == n) {
    maxcrk = max(crk, maxcrk);
    return;
  }

  // step 2
  if (egg[now].hp <= 0) // hand is cracked
    dfs(now + 1, crk);
  else {

    bool atked = false;
    for (int i = 0; i < n; i++) {
      if (now == i)
        continue;

      if (egg[i].hp > 0) { // do attack
        atked = true;

        egg[i].hp -= egg[now].atk;
        egg[now].hp -= egg[i].atk;

        dfs(now + 1,
            crk + (egg[now].hp > 0 ? 0 : 1) +
                (egg[i].hp > 0 ? 0 : 1)); // step 3

        egg[i].hp += egg[now].atk;
        egg[now].hp += egg[i].atk;
      }
    }

    // step 3 when no atk
    if (!atked) {
      maxcrk = max(crk, maxcrk);
      return;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  egg.resize(n);
  for (int i = 0; i < n; i++)
    cin >> egg[i].hp >> egg[i].atk;
  dfs(0, 0);
  cout << maxcrk;

  return 0;
}
