// BOJ 25305
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
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end(),greater<int>());
  cout<<v[k-1];

  return 0;
}
