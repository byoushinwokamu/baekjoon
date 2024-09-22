#include <cstring>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  char pal[6] = "";
  cin >> pal;
  while (pal[0] != '0') {
    int len = strlen(pal);
    bool bull = true;
    for (int i = 0; i < len / 2; i++)
      if (pal[i] != pal[len - i - 1])
        bull = false;
    cout << (bull ? "yes" : "no") << '\n';
    cin >> pal;
  }

  return 0;
}