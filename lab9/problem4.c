#include <stdio.h>

int *G;

int f(void) {
  int l = 1;
  printf("%d\n",l);
  int res = *G;
  G = &l;
  return res;
}

int main(void) {
  int x = 2;
  G = &x;
  f();
  printf("f is %d\n", f());
}
