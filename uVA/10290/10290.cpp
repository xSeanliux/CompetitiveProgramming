#include <iostream>
using namespace std;

bool sieve[3000000];
int primes[3000000];
int factorization[3000000];
int head = 0;
long long int a;


int SieveOfAtkin(int limit)
{
    // 2 and 3 are known to be prime
    primes[0] = 2; primes[1] = 3;
    head = 2;
    // Initialise the sieve array with false values

    for (int i=0; i<limit; i++)
        sieve[i] = false;
    //cout << "gg" << endl;

    /* Mark siev[n] is true if one of the following is true:
     a) n = (4*x*x)+(y*y) has odd number of solutions, i.e., there exist
        odd number of distinct pairs (x, y) that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
     b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
     c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */
    for (int x = 1; x*x < limit; x++)
    {
        for (int y = 1; y*y < limit; y++)
        {
            // Main part of Sieve of Atkin
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    // Mark all multiples of squares as non-prime
    for (int r = 5; r*r < limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r*r; i < limit; i += r*r)
                sieve[i] = false;
         }
    }

    // Print primes using sieve[]
    for (int a = 5; a < limit; a++){
        if (sieve[a]){
            //cout << a << endl;
            primes[head] = a;
            head++;
        }
    }


}




int main(){
    primes[0] = 2;
    SieveOfAtkin(3000000);
    //cout << "a" << endl;
    while(cin >> a){
        if(a == 0){
            cout << 0 << endl;
        } else if( a <= 2 ){
            cout << 1 << endl;
        } else {
            while( a % 2 == 0){
                a /= 2;
            }

            int ans = 1;
            for(int i = 0; i < head; i++){
                if(a % primes[i] == 0){
                        factorization[primes[i]] = 0;
                        while(a % primes[i] == 0){
                            //cout << primes[i] << " is a factor" << endl;
                            a /= primes[i];
                            factorization[primes[i]]++;
                                     //           cout << primes[i] << "^" << factorization[primes[i]] << " * " << endl;

                    }
                    ans *= (factorization[primes[i]] + 1);
                }
                if(a == 1){
                    break;
                }
            }
            //cout << a << endl;
            if (a>1) ans<<=1;

            //cout << "finished" <<endl;

            cout << ans << endl;
        }
    }
}
