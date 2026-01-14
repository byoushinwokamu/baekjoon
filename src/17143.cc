// BOJ 17143
#include <algorithm>
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
  pp pos;
  int speed;
  int dir;
  int siz;
} shark_t;

// #define DEBUG

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int r, c, m;
  cin >> r >> c >> m;
  vector<shark_t> shark(m);
  vector<int> ocean((r + 1) * (c + 1), -1);
  vector<int> ocean_after((r + 1) * (c + 1), -1);
  vector<int> eaten; // shark index

  auto conv = [&c](const pp &p)
  { return p.fi * c + p.se; };

  auto move = [&r, &c](pp p, int s, int &d)
  {
    switch (d)
    {
    case 1: // up
      p.fi -= s;
      if (p.fi >= 1) s = 0;
      else s = 1 - p.fi, p.fi = 1, d = 2;
      if (s)
      {
        p.fi += s;
        if (p.fi <= r) s = 0;
        else s = p.fi - r, p.fi = r, d = 1;
        if (s) p.fi -= s;
      }
      break;
    case 2: // down
      p.fi += s;
      if (p.fi <= r) s = 0;
      else s = p.fi - r, p.fi = r, d = 1;
      if (s)
      {
        p.fi -= s;
        if (p.fi >= 1) s = 0;
        else s = 1 - p.fi, p.fi = 1, d = 2;
        if (s) p.fi += s;
      }
      break;
    case 3: // right
      p.se += s;
      if (p.se <= c) s = 0;
      else s = p.se - c, p.se = c, d = 4;
      if (s)
      {
        p.se -= s;
        if (p.se >= 1) s = 0;
        else s = 1 - p.se, p.se = 1, d = 3;
        if (s) p.se += s;
      }
      break;
    case 4: // left
      p.se -= s;
      if (p.se >= 1) s = 0;
      else s = 1 - p.se, p.se = 1, d = 3;
      if (s)
      {
        p.se += s;
        if (p.se <= c) s = 0;
        else s = p.se - c, p.se = c, d = 4;
        if (s) p.se -= s;
      }
      break;
    }
    return p;
  };

  for (int i = 0; i < m; i++)
  {
    cin >> shark[i].pos.fi >> shark[i].pos.se >> shark[i].speed >> shark[i].dir >> shark[i].siz;
    shark[i].speed %= (shark[i].dir <= 2) ? (2 * r - 2) : (2 * c - 2);
    ocean[conv(shark[i].pos)] = i;
  }

  int money = 0;
  for (int king = 1; king <= c; king++)
  {

#ifdef DEBUG
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>> KING is on " << king << endl;
#endif

    // 왕의 낚시
    for (int depth = 1; depth <= r; depth++)
    {
      int cdk = conv({depth, king});
      if (ocean[cdk] != -1)
      {

#ifdef DEBUG
        cout << "Walcheok at " << depth << ' ' << king << endl;
#endif

        money += shark[ocean[cdk]].siz;
        shark[ocean[cdk]] = shark.back();
        ocean[cdk] = -1;
        shark.pop_back();
        break;
      }
    }

#ifdef DEBUG
    cout << "Fishing complete" << endl;
    cout << "shark nokori " << shark.size() << endl;
#endif

    // 상어의 이동
    for (auto it = shark.begin(); it != shark.end(); it++)
    {
      pp newpos = move(it->pos, it->speed, it->dir);
      // pp newpos = it->pos;
      int cnp = conv(newpos);

#ifdef DEBUG
      cout << "Moved from " << it->pos.fi << ' ' << it->pos.se << " to " << newpos.fi << ' ' << newpos.se << endl;
#endif

      it->pos = newpos;
      if (ocean_after[cnp] != -1) // 해당 위치에 이미 상어가 존재
      {
        if (shark[ocean_after[cnp]].siz < it->siz) // 잡아먹을 수 있음
          eaten.push_back(ocean_after[cnp]), ocean_after[cnp] = it - shark.begin();
        else // 잡아먹힘
          eaten.push_back(it - shark.begin());
      }
      else // 상어 없는 자리
        ocean_after[cnp] = it - shark.begin();
    }
    sort(eaten.begin(), eaten.end(), greater<int>());

#ifdef DEBUG
    cout << eaten.size() << " sharks are eaten" << endl;
#endif

    for (auto i : eaten)
    {
      if (i != shark.size() - 1)
      {
        shark[i] = shark.back();
        ocean_after[conv(shark[i].pos)] = i;
      }
      shark.pop_back();
    }
    eaten.clear();
    ocean = ocean_after;
    fill(ocean_after.begin(), ocean_after.end(), -1);

#ifdef DEBUG
    cout << "Moving complete" << endl;
    cout << "shark nokori " << shark.size() << endl;
    for (auto sh : shark)
    {
      cout << sh.pos.fi << ' ' << sh.pos.se << ' ' << sh.siz << '\n';
    }
    cout << "King moves..." << endl;
#endif
  }
  cout << money;

  return 0;
}
