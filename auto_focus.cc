#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argv, char **args) {
  if (argv < 2) {
    cout << "ERROR: Too few arguments" << endl;
    return 0;
  }
  char touch[100] = "cp -i ~/baekjoon/src/templete.cc ~/baekjoon/src/";
  char link[100] = "ln -f ~/baekjoon/src/";
  strcat(touch, args[1]);
  strcat(touch, ".cc");
  strcat(link, args[1]);
  strcat(link, ".cc ~/baekjoon/focus.cc");

  system(touch);
  system(link);
  return 0;
}
