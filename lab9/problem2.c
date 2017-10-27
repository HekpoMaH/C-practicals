#include <stdio.h>

void foo(int i) { 
  while (i) { 
    /* loop? */
  }
}

int main(void) { 
  foo(1); 
  printf("Done!?\n");
  return 0;
}
