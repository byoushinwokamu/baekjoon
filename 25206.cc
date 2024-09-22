#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n = 20;
  int pois = 0;
  double sco = 0;
  char na[100], po[10], sc[10];
  for (int i = 0; i < 20; i++) {
    scanf("%s %s %s", na, po, sc);
    if (sc[0] == 'P')
      n--;
    else {
      int poi;
      poi = po[0] - '0';
      pois += poi;
      if (sc[0] == 'F')
        continue;
      if (sc[0] == 'A')
        sco += 4 * poi;
      else if (sc[0] == 'B')
        sco += 3 * poi;
      else if (sc[0] == 'C')
        sco += 2 * poi;
      else if (sc[0] == 'D')
        sco += 1 * poi;
      if (sc[1] == '+')
        sco += 0.5 * poi;
    }
  }
  printf("%f\n", sco / pois);

  return 0;
}