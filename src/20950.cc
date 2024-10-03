#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

typedef struct {
  int r;
  int g;
  int b;
} color;

int n;
vector<color> v;
color gom;
vector<int> mix;
int bestdiff = INT32_MAX;

void back(int depth, int ta) {
  if (depth > 1) {
    color mixed = {0, 0, 0};
    for (int m : mix) {
      mixed.r += v[m].r;
      mixed.g += v[m].g;
      mixed.b += v[m].b;
    }
    mixed.r /= mix.size();
    mixed.g /= mix.size();
    mixed.b /= mix.size();
    int diff =
        abs(gom.r - mixed.r) + abs(gom.g - mixed.g) + abs(gom.b - mixed.b);
    bestdiff = min(diff, bestdiff);
  }
  if (depth < 7) {
    for (int i = ta + 1; i < n; i++) {
      mix.push_back(i);
      back(depth + 1, i);
      mix.pop_back();
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].r >> v[i].g >> v[i].b;

  cin >> gom.r >> gom.g >> gom.b;
  back(0, -1);
  cout << bestdiff;

  return 0;
}