#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> m;

int d(int s1, int s2) {
  s1 = s1 ^ s2;
  return (s1 & 1) + (s1 & 2) / 2 + (s1 & 4) / 4 + (s1 & 8) / 8;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t, n;
  string s;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    cin >> n;
    int stu[16] = {
        0,
    };
    for (int i = 0; i < n; i++) {
      cin >> s;
      stu[(s[0] == 'I' ? 1 : 0) + (s[1] == 'S' ? 2 : 0) +
          (s[2] == 'F' ? 4 : 0) + (s[3] == 'J' ? 8 : 0)]++;
    }
    int mindis = 300;
    for (int i = 0; i < 16; i++) {
      if (!stu[i])
        continue;
      for (int j = 0; j < 16; j++) {
        if (!stu[j])
          continue;
        if (i == j && stu[i] < 2)
          continue;
        for (int k = 0; k < 16; k++) {
          if (!stu[k])
            continue;
          if ((i == k || j == k) && stu[k] < 2)
            continue;
          if (i == k && j == k && stu[k] < 3)
            continue;
          int dist = d(i, j) + d(j, k) + d(k, i);
          mindis = mindis < dist ? mindis : dist;
        }
      }
    }
    cout << mindis << '\n';
  }

  return 0;
}