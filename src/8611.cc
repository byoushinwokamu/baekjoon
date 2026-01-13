// BOJ 8611
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
  string n;
} bigint;

bigint operator/(bigint r, int d)
{
  string q;
  for (auto c : r.n)
  {
  }
  return r;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string n;
  cin >> n;
  for (int b = 2; b <= 10; b++)
  {
    // base transform
    string d = n;
    string res; // result is reversed, but doesn't matter 'cause we wanna find pallindrome
    string q;
    int r = 0;
    for (char c : n)
    {
      r *= 10;
      r += c - '0';
    }
  }

  return 0;
}
