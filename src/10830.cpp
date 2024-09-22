#include <iostream>

using namespace std;

int mat[3][5][5]; // 0 is now, 1 is result, 2 is temp
int n;

void matmov(int f, int d) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      mat[d][i][j] = mat[f][i][j];
}

void matmul(int a, int b, int r) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[r][i][j] = 0;
      for (int k = 0; k < n; k++) {
        mat[r][i][j] += mat[a][i][k] * mat[b][k][j];
        mat[r][i][j] %= 1000;
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  long long b;
  cin >> n >> b;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> mat[0][i][j];
      mat[1][i][j] = (i == j) ? 1 : 0;
    }

  while (b > 0) {
    if (b % 2 == 1) {
      matmul(0, 1, 2);
      matmov(2, 1);
    }
    matmul(0, 0, 2);
    matmov(2, 0);
    b /= 2;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << mat[1][i][j] << " ";
    cout << "\n";
  }

  return 0;
}