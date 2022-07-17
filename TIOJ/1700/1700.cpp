#include <stdio.h>



int input(int* a) { 
 static char p, q;
 while (q = read(0, &p, 1), p < '0')
  if (!q) return 0;
 *a = p ^ '0';
 while (read(0, &p, 1), p >= '0') *a = *a * 10 + (p ^ '0');
 return 1;
}

int main(){
int N, x, g;
	while(input(&N)){
		input(&g);
		while(--N){
			input(&x);
			while(x){
				g %= x;
				x ^= g ^= x ^= g;
			}
		}
		printf("%d\n", g);
	}
}
