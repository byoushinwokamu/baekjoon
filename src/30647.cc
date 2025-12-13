// BOJ 30647
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

typedef struct
{
  string name;
  int score;
  int hid;
} man;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;

  char input[60];
  vector<man> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    strtok(input, ":");
    v[i].name = strtok(NULL, "\"");

    strtok(NULL, ":");
    v[i].score = atoi(strtok(NULL, ","));

    strtok(NULL, ":");
    v[i].hid = atoi(strtok(NULL, "}"));
  }

  sort(v.begin(), v.end(), [](const man &a, const man &b)
       { return a.score == b.score ? a.name < b.name : a.score > b.score; });

  int sw = 1; // soonwie
  for (int i = 0; i < n; i++)
  {
    if (i && v[i - 1].score > v[i].score) sw = i + 1;
    if (v[i].hid) continue;
    cout << sw << ' ' << v[i].name << ' ' << v[i].score << '\n';
  }

  return 0;
}
