#include <stdlib.h>
#include <stdio.h>
#include "re.h"

arena_t create_arena(int size) { 
    arena_t arena=malloc(sizeof(struct arena));
    arena->size=size;
    arena->current=0;
    arena->elts=malloc(size*sizeof(Regexp));
    return arena;
}

void arena_free(arena_t a) { 
    free(a->elts);
    free(a);
}

Regexp *re_alloc(arena_t a) { 
    if(a->current==a->size)
        return NULL;
    //allocate new regexp
    Regexp *r=a->elts+a->current;
    a->current++;
    return r;
}

Regexp *re_chr(arena_t a, char c) { 
    Regexp *r=re_alloc(a);
    if(r==NULL)
        return NULL;
    r->data.chr=c;
    r->type=CHR;
    return r;
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2) { 
    Regexp *r=re_alloc(a);
    if(r==NULL)
        return NULL;
    r->type=ALT;
    r->data.pair.fst=r1;
    r->data.pair.snd=r2;
    return r;
  return NULL;
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2) { 
    Regexp *r=re_alloc(a);
    if(r==NULL)
        return NULL;
    r->type=SEQ;
    r->data.pair.fst=r1;
    r->data.pair.snd=r2;
    return r;
}

bool isChar(char x){
    return (x>='a'&&x<='z')||(x>='A'&&x<='Z');
}
int re_match(Regexp *r, char *s, int i) { 
    if(r==NULL)
        return -1;
    switch(r->type){
        int nwi;
        case CHR:
            if(s[i]==r->data.chr)
                return i+1;
            else
                return -1;
            break;
        case SEQ:
            nwi=re_match(r->data.pair.fst,s,i);
            if(nwi==-1)
                return -1;
            nwi=re_match(r->data.pair.snd,s,nwi);
            if(nwi==-1)
                return -1;
            return nwi;
            break;
        case ALT:
            nwi=re_match(r->data.pair.fst,s,i);
            if(nwi==-1)
                nwi=re_match(r->data.pair.snd,s,i);
            return nwi;
            break;
    }
    return -1;
}



void re_print(Regexp *r) { 
  if (r != NULL) { 
    switch (r->type) {
    case CHR: 
      printf("%c", r->data.chr);
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT) { 
	printf("(");
	re_print(r->data.pair.fst);
	printf(")");
      } else {
	re_print(r->data.pair.fst);
      }
      if (r->data.pair.snd->type == ALT) { 
	printf("(");
	re_print(r->data.pair.snd);
	printf(")");
      } else {
	re_print(r->data.pair.snd);
      }
      break;
    case ALT:
      re_print(r->data.pair.fst);
      printf("+");
      re_print(r->data.pair.snd);
      break;
    }
  } else { 
    printf("NULL");
  }
}    


      
  
