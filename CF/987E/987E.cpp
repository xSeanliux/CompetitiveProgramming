#include <iostream>
using namespace std;

const int maxN = 1e6 + 10;

bool visited[maxN];
int perm[maxN], N, cnt;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> perm[i];
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            cnt++;
            visited[i] = true;
            for(int x = perm[i]; x != i; x = perm[x]) visited[x] = true;
        }
    }
    cout << ((cnt % 2) == 0 ? "Petr" : "Um_nik") << endl;
}
