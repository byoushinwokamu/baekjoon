#include <iostream>

using namespace std;

typedef struct _node {
  int v = 0;
  struct _node *l = NULL;
  struct _node *r = NULL;
} Node;

void post(Node *n) {
  if (!n)
    return;
  post(n->l);
  post(n->r);
  cout << n->v << '\n';
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int v;
  Node *root = new Node;
  cin >> root->v;
  Node *nn = new Node;
  cin >> nn->v;
  while (!cin.fail()) {
    Node *now = root;
    while (true) {
      if (nn->v < now->v) {
        if (!now->l) {
          now->l = nn;
          break;
        }
        now = now->l;
      } else {
        if (!now->r) {
          now->r = nn;
          break;
        }
        now = now->r;
      }
    }
    nn = new Node;
    cin >> nn->v;
  }
  post(root);

  return 0;
}