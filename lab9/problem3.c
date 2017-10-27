/* Find different optimization levels which will change the
   behaviour of the program. */

void foo(int i) { 
  foo(i+1);
}


int main(void) { 
  foo(0);
  return 0;
}
