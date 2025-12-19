// BOJ 9229
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
  string sa, sb;
  cin>>sb;
  while(true)
  {
    bool cor = true;

    while(sb!="#"){
      sa=sb;cin>>sb;

      int cnt = 0;
      int sz = min(sa.size(), sb.size());
      if(sa.size()!=sb.size()) {cor = false; continue;}
      for(int i=0;i<sz;i++)
        if(sa[i]!=sb[i]) cnt++;
      if(cnt!=1) cor = false;
    }

    cout<<(cor?"Correct\n":"Incorrect\n");
    if(sa=="#"&&sb=="#") break;
  }

  return 0;
}
