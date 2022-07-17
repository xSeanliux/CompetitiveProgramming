#include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>

int genius_distinguisher (uint64_t value );
int main () {
 volatile uint64_t b; // available values are 0 and 1
 volatile uint64_t x0;
 volatile uint64_t x1;
 volatile uint64_t secret;
 scanf("%lu%lu%lu", &b, &x0 , &secret );
 
 //printf("x0 = %p, x1 = %p\n", &x0,&x1);
 x1 = x0 + 1;

 if (b == genius_distinguisher (b ? x1 : x0))
 printf("win: %lu\n", secret );
 else
 printf("lose ><\n");

 return 0;
 }

int genius_distinguisher (uint64_t value) {
     uint64_t jizz;
     uint64_t *add = &jizz;
     for(int i = -64; i < 64; i++){
         if(*(add + i) == value){
             if((*(add + i + 1) == value + 1) || (*(add + i - 1) == value + 1)){
                 return 0;
             } 
             if((*(add + i + 1) == value - 1) || (*(add + i - 1) == value - 1)){
                 return 1;
             }
         }
     }
}


