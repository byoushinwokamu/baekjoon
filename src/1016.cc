// BOJ 1016
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<bool> inp(1'000'001); // is not prime number
vector<ll> prime;
ll a, b, c;

void dfs(ll now, int idx)
{
  // cout << "checked " << now << endl;
  if (now > b) return;
  for (; idx < prime.size();)
  {
    ll next = now * prime[idx];
    if (next > b) break;
    if (next >= a && next <= b)
      c++;
    if (next < b)
      dfs(next, idx + 1);
    idx++;
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  inp[1] = true;
  for (ll i = 2; i <= 1'000'001; i++)
  {
    if (inp[i]) continue;
    prime.push_back(i);
    for (ll j = 2; i * j <= 1'000'001; j++)
      inp[i * j] = true;
  }
  // for (int i = 0; i < 20; i++) cout << prime[i] << endl;
  // return 0;
  cin >> a >> b;
  if (a == 1) c++;
  dfs(1, 0);
  cout << c;

  return 0;
}