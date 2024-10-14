#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define fi first
#define se second
typedef long long ll;

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    double a, b, c;
    scanf(" %lf %lf %lf", &a, &b, &c);
    printf("$%.2f\n", a * b * c);
  }
  return 0;
}
