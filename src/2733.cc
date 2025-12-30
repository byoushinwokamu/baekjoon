// BOJ 2733
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cout << "PROGRAM #" << i << ":\n";
    string buf, prog, res;
    vector<int> reg(32768);
    int pointer = 0;

    bool error = false;

    while (buf != "end")
    {
      getline(cin, buf);
      prog.append(buf.substr(0, buf.find('%')));
    }
    vector<int> link(prog.size());

    int b = 0;
    for (int i = 0; i < prog.length(); i++)
    {
      if (prog[i] == '[')
        b++;
      else if (prog[i] == ']')
        b--;
      if (b < 0)
        error = true;
    }
    if (b != 0)
      error = true;

    if (error)
    {
      cout << "COMPILE ERROR\n";
      continue;
    }

    stack<int> s;
    for (int i = 0; i < prog.length(); i++)
    {
      if (prog[i] == '[')
        s.push(i);
      else if (prog[i] == ']')
        link[i] = s.top(), link[s.top()] = i, s.pop();
    }

    int branow = -1;
    for (int cur = 0; cur < prog.length(); cur++)
    {
      switch (prog[cur])
      {
      case '>':
        pointer = (pointer + 1) & 0x7FFF;
        break;
      case '<':
        pointer = (pointer + 32767) & 0x7FFF;
        break;
      case '+':
        reg[pointer] = (reg[pointer] + 1) & 0xFF;
        break;
      case '-':
        reg[pointer] = (reg[pointer] + 255) & 0xFF;
        break;
      case '.':
        res.append(1, (char)reg[pointer]);
        break;
      case '[':
        if (reg[pointer] == 0)
          cur = link[cur];
        else
          branow++;
        break;
      case ']':
        if (reg[pointer] != 0)
          cur = link[cur];
        else
          branow--;
        break;
      }
    }

    cout << res << '\n';
  }

  return 0;
}
