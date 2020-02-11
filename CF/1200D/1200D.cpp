#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2019;

int k, n;
char mp[maxN][maxN];
pii cole[maxN], rowe[maxN];
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cole[i] = rowe[i] = {n, -1};
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        cin >> mp[i][j];
        if(mp[i][j] == 'B'){
            rowe[i].F = min(rowe[i].F, j);
            rowe[i].S = j;
            cole[j].F = min(cole[j].F, i);
            cole[j].S = i;
        }
    }
    int ans = 0, c;
    for(int i = 0; i < n; i++){
        ans += (rowe[i].S == -1);
        ans += (cole[i].S == -1);
    }
    for(int i = 0; i < n; i++){
        if(rowe[i].S - rowe[i].F >= 0 && rowe[i].S - rowe[i].F < k){
            c = 0;
            //cout << "Clicking " << i << ", " << rowe[i].F << endl;
            for(int j = 0; j < n; j++){
                //cout << "J = " << j << endl;
                if(j >= i && j < i + k)
                    c += ((rowe[i].F <= rowe[j].F && rowe[j].S < rowe[i].F + k) || rowe[j].S == -1);
                else c += (rowe[j].S == -1);

                if(j >= rowe[i].F && j < rowe[i].F + k)
                    c += ((i <= cole[j].F && cole[j].S < i + k) || cole[j].S == -1);
                else c += (cole[j].S == -1);
            }
            //cout << "Getting " << c << " lines" << endl;
            ans = max(ans, c);
        }
    }
    for(int i = 0; i < n; i++){
        if(cole[i].S - cole[i].F >= 0 && cole[i].S - cole[i].F < k){
            c = 0;
            //cout << "Clicking " << cole[i].F << ", " << i << endl;
            for(int j = 0; j < n; j++){
                if(j >= i && j < i + k)
                    c += ((cole[i].F <= cole[j].F && cole[j].S < cole[i].F + k) || cole[j].S == -1);
                else c += (cole[j].S == -1);

                if(j >= cole[i].F && j < cole[i].F + k)
                    c += ((i <= rowe[j].F && rowe[j].S < i + k) || rowe[j].S == -1);
                else c += rowe[j].S == -1;
            }
            //cout << "Getting " << c << " lines" << endl;
            ans = max(ans, c);
        }
    }
    cout << ans << endl;
}


