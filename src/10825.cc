// BOJ 10825
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

typedef struct stu
{
  string name;
  int kor;
  int eng;
  int mat;
} student;

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<student> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].mat;

  sort(v.begin(), v.end(), [](const student &a, const student &b)
       {
         if (a.kor != b.kor) return a.kor > b.kor;
         if (a.eng != b.eng) return a.eng < b.eng;
         if (a.mat != b.mat) return a.mat > b.mat;
         return a.name < b.name;
       });

  for (auto s : v) cout << s.name << '\n';

  return 0;
}
