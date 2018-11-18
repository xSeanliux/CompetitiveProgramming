#include <iostream>
#include <math.h>
using namespace std;


int N, c;
bool isPrime[100];
int solArr[100];
bool visited[100];
void getPrimes(){
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i < 100; i++){
        if(isPrime[i]){
            for(int j = i*i; j < 100; j+=i){
                isPrime[j] = false;

            }
        }
    }
}

bool isValid(int arr[]){
    for(int i = 0; i < N; i++){
        if(!isPrime[arr[i] + arr[(i + 1)%N]]){
            //cout << arr[i] + arr[((i + 1)%N)] << endl;
            return false;

        }
    }
    return true;
}

void dfs(int now){
    if(now == N){
        if(isPrime[solArr[0] + solArr[N-1]]){
            for(int i = 0; i < N ; i++){
            if(i > 0){
                cout << " ";
            }
            cout << solArr[i];

        }
        cout << endl;
        }

        return;
    }else{
        for(int i = 2; i <= N; i++){
            if(!visited[i] && isPrime[i + solArr[now-1]]){
                visited[i] = true;
                solArr[now] = i;
                dfs(now + 1);
                visited[i] = false;
            }

        }
        return;
    }

}


int main(){
    c = 1;
    for(int i = 0; i <= 100; i++){
        isPrime[i] = true;
    }
    getPrimes();
    while(cin >> N){

        if(c != 1){
            cout << endl;
        }
        printf("Case %d:\n" , c);
        for(int i = 0; i <= N; i++){
            visited[i] = false;
        }
        solArr[0] = 1;
        visited[0] = true;
        dfs(1);
        c++;
    }
}


